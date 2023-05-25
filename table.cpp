#include "table.hpp"
#include "stdio.h"
#include <cassert>
#include "config.hpp"

Table::Table(int n) {
    // TODO: implement table constructor (value, mutex, cond)
    
    // mutex = PTHREAD_MUTEX_INITIALIZER;
    // cond = PTHREAD_COND_INITIALIZER; 

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    value = n - 1;  

#ifdef DEBUG        
    logger.add_meta(ll2str(value));
    logger.add_meta(ll2str(PHILOSOPHERS));    
#endif
}



void Table::wait(
#ifdef DEBUG        
    int phr_id
#endif
    ) {
    // TODO: implement semaphore wait
    pthread_mutex_lock(&mutex);

    while(value == 0){
#ifdef DEBUG        
        logger.add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE" + ", " + ll2str(value));
#endif

        pthread_cond_wait(&cond, &mutex);
    } 

    value--;
    assert(value >= 0);

#ifdef DEBUG        
    logger.add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE" + ", " + ll2str(value));
#endif

    pthread_mutex_unlock(&mutex);    
}




void Table::signal(
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

Table::~Table() {

#ifdef DEBUG        
    char buf[20];
    sprintf(buf, "Table.log");
    logger.write_log(buf);
#endif

    // TODO: implement table destructor (mutex, cond)
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}