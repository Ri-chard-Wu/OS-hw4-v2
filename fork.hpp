#ifndef FORK_HPP
#define FORK_HPP
#include <pthread.h>
#include <iostream>

#include "utils.hpp"

using namespace std;




class Fork {
public:
    Fork(int id);
    void wait(int phr_id);
    void signal(int phr_id); 
    ~Fork();

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;

    int id;
    Logger logger;
};



#endif // FORK_HPP