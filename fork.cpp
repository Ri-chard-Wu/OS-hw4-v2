#include "fork.hpp"
#include <cassert>
#include "config.hpp"

using namespace std;

Fork::Fork(
#ifdef DEBUG        
    int id
#endif
    ) {
    // TODO: implement fork constructor (value, mutex, cond)
#ifdef DEBUG        
    this->id = id;
#endif

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    value = 1;

#ifdef DEBUG        
    logger.add_meta(ll2str(value));
    logger.add_meta(ll2str(PHILOSOPHERS));       
#endif

}



void Fork::wait(
#ifdef DEBUG        
    int phr_id
#endif
) {
    // TODO: implement semaphore wait

    pthread_mutex_lock(&mutex);

    while(value == 0) {
#ifdef DEBUG        
        logger.add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE" + ", " + ll2str(value));
#endif
        pthread_cond_wait(&cond, &mutex);

    };

    value--;
    assert(value >= 0);

#ifdef DEBUG        
    logger.add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE" + ", " + ll2str(value));
#endif

    pthread_mutex_unlock(&mutex);
}


void Fork::signal(
#ifdef DEBUG        
    int phr_id
#endif    
) {
    // TODO: implement semaphore signal
    pthread_mutex_lock(&mutex);
    value++;
    
    pthread_cond_signal(&cond);

#ifdef DEBUG        
    logger.add_log(ll2str(phr_id) + ", RELEASED_RESOURCE" + ", " + ll2str(value));
#endif

    pthread_mutex_unlock(&mutex);
}

Fork::~Fork() {
    // TODO: implement fork destructor (mutex, cond)

#ifdef DEBUG        
    char buf[20];
    sprintf(buf, "Fork-%d.log", id);
    logger.write_log(buf);
#endif

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}