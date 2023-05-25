
// #ifndef FORK_HPP
// #define FORK_HPP

// #include <pthread.h>

// class Fork {
// public:
//     Fork();
//     void wait();
//     void signal(); 
//     ~Fork();
// private:
//     pthread_mutex_t mutex;
//     pthread_cond_t cond;
//     int value;
// };

// #endif // FORK_HPP




#ifndef FORK_HPP
#define FORK_HPP
#include <pthread.h>
#include <iostream>

#include "utils.hpp"

using namespace std;
#define DEBUG

class Fork {
public:
    Fork(
#ifdef DEBUG        
        int id
#endif
        );
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