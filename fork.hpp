
#ifndef FORK_HPP
#define FORK_HPP

#include <pthread.h>

class Fork {
public:
    Fork();
    void wait();
    void signal(); 
    ~Fork();
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
};

#endif // FORK_HPP


// -------------------------------------------------------



// #include "utils.hpp"




// #ifndef FORK_HPP
// #define FORK_HPP

// #include <pthread.h>
// #include <iostream>


// class Fork {
// public:
//     Fork(
// #ifdef DEBUG        
//         int id
// #endif
//         );
//     void wait(
// #ifdef DEBUG           
//         int phr_id
// #endif        
//         );
//     void signal(
// #ifdef DEBUG        
//         int phr_id
// #endif        
//         ); 
//     ~Fork();

// private:
//     pthread_mutex_t mutex;
//     pthread_cond_t cond;
//     int value;

// #ifdef DEBUG   
//     int id;
//     Logger logger;
// #endif     
// };

// #endif