#include "fork.hpp"
#include <cassert>

#include <sys/time.h>
#include <fstream>

using namespace std;
// using namespace std::chrono;

Fork::Fork(int id): id(id) {
    // TODO: implement fork constructor (value, mutex, cond)

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    value = 1;
}


// long long get_time(){
//     return (long long)(duration_cast<milliseconds>(\
//             std::chrono::system_clock::now().time_since_epoch()).count());
// }



long long get_time(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}




string ll2str(long long n){
    char buf[20];
    sprintf(buf, "%lld", n);
    return ((string)buf);
}


void Fork::add_log(string msg){
    msg = ll2str(get_time()) + ", " + msg;
    log_array.push_back(msg);
}



void Fork::write_log(){

    char buf[20];
    sprintf(buf, "Fork-%d.log", id);
    ofstream out(buf);

    out << "Meta:\n";
    out << "n_resource 1\n";

    out << "Body:\n";
    for(int i = 0; i < log_array.size(); i++){
        out << log_array[i] << "\n";
    }
    out.close();
}



void Fork::wait(int phr_id) {
    // TODO: implement semaphore wait

    pthread_mutex_lock(&mutex);

    while(value == 0) {
        add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE");

        pthread_cond_wait(&cond, &mutex);

    };

    value--;
    
    assert(value >= 0);

    add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE");
    pthread_mutex_unlock(&mutex);
}


void Fork::signal(int phr_id) {
    // TODO: implement semaphore signal
    pthread_mutex_lock(&mutex);
    value++;
    
    pthread_cond_signal(&cond);

    add_log(ll2str(phr_id) + ", RELEASED_RESOURCE");

    pthread_mutex_unlock(&mutex);
}

Fork::~Fork() {
    // TODO: implement fork destructor (mutex, cond)
    write_log();
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}