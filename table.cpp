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

    logger.add_meta(ll2str(value));
    logger.add_meta(ll2str(PHILOSOPHERS));    
}



void Table::wait(int phr_id) {
    // TODO: implement semaphore wait
    pthread_mutex_lock(&mutex);

    while(value == 0){
        logger.add_log(ll2str(phr_id) + ", WAIT_ON_RESOURCE" + ", " + ll2str(value));
        pthread_cond_wait(&cond, &mutex);
    } 

    value--;
    assert(value >= 0);

    logger.add_log(ll2str(phr_id) + ", ACQUIRED_RESOURCE" + ", " + ll2str(value));

    pthread_mutex_unlock(&mutex);    
}




void Table::signal(int phr_id) {
    // TODO: implement semaphore signal

    pthread_mutex_lock(&mutex);
    value++;
    pthread_cond_signal(&cond);

    logger.add_log(ll2str(phr_id) + ", RELEASED_RESOURCE" + ", " + ll2str(value));

    pthread_mutex_unlock(&mutex);
}

Table::~Table() {

    char buf[20];
    sprintf(buf, "Table.log");
    logger.write_log(buf);

    // TODO: implement table destructor (mutex, cond)
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}