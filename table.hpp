#ifndef TABLE_HPP
#define TABLE_HPP

#include <pthread.h>

#include "utils.hpp"

class Table {
public:
    Table(int n);
    void wait(int phr_id);
    void signal(int phr_id);
    ~Table();


private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;

    int id;
    Logger logger;    
};



#endif // TABLE_HPP