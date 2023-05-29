#include "fork.hpp"
#include "config.hpp"

using namespace std;

Fork::Fork(int id) {
    // TODO: implement fork constructor (value, mutex, cond)
    this->id = id;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    value = 1;


    // pthread_mutex_init(&mutex_tk, NULL);
    tk_serving = 0;
    n_tk_max = PHILOSOPHERS;
    tk_next = 0;
    
    logger.add_meta(ll2str(value));
    logger.add_meta(ll2str(PHILOSOPHERS));       
}



void Fork::wait(int phr_id) {
    // TODO: implement semaphore wait
    pthread_mutex_lock(&mutex);

    int tk = draw_tk();

    while(value == 0 || tk != tk_serving) {
        
        logger.add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE" + ", " + ll2str(value));

        pthread_cond_wait(&cond, &mutex);
    };

    value--;
    tk_serving = (tk_serving + 1) % n_tk_max;
    
    logger.add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE" + ", " + ll2str(value));


    pthread_mutex_unlock(&mutex);
}



void Fork::signal(int phr_id) {
    // TODO: implement semaphore signal
    pthread_mutex_lock(&mutex);
    value++;
    
    pthread_cond_broadcast(&cond);

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