#include "fork.hpp"

#include <cassert>


using namespace std;
// using namespace std::chrono;

Fork::Fork(int id): id(id) {
    // TODO: implement fork constructor (value, mutex, cond)

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    value = 1;

    logger.add_meta(ll2str(1));
}





// void Fork::add_log(string msg){
//     msg = ll2str(get_time()) + ", " + msg;
//     log_array.push_back(msg);
// }



// void Fork::write_log(){

//     char buf[20];
//     sprintf(buf, "Fork-%d.log", id);
//     ofstream out(buf);

//     // out << "Meta:\n";
//     out << "1\n";

//     // out << "Body:\n";
//     for(int i = 0; i < log_array.size(); i++){
//         out << log_array[i] << "\n";
//     }
//     out.close();
// }



void Fork::wait(int phr_id) {
    // TODO: implement semaphore wait

    pthread_mutex_lock(&mutex);

    while(value == 0) {
        logger.add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE" + ", " + ll2str(value));

        pthread_cond_wait(&cond, &mutex);

    };

    value--;
    
    assert(value >= 0);

    logger.add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE" + ", " + ll2str(value));
    pthread_mutex_unlock(&mutex);
}


void Fork::signal(int phr_id) {
    // TODO: implement semaphore signal
    pthread_mutex_lock(&mutex);
    value++;
    
    pthread_cond_signal(&cond);

    logger.add_log(ll2str(phr_id) + ", RELEASED_RESOURCE" + ", " + ll2str(value));

    pthread_mutex_unlock(&mutex);
}

Fork::~Fork() {
    // TODO: implement fork destructor (mutex, cond)

    char buf[20];
    sprintf(buf, "Fork-%d.log", id);
    logger.write_log(buf);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}