
#ifndef TABLE_HPP
#define TABLE_HPP

#include <pthread.h>

class Table {
public:
    Table(int n);
    void wait();
    void signal();
    ~Table();

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;

};



#endif // TABLE_HPP



// -------------------------------------------------------


// #include "utils.hpp"







// #ifndef TABLE_HPP
// #define TABLE_HPP

// #include <pthread.h>


// class Table {
// public:
//     Table(int n);

//     void wait(
// #ifdef DEBUG        
//         int phr_id
// #endif
//     );

//     void signal(
// #ifdef DEBUG        
//         int phr_id
// #endif
//     );

//     ~Table();


// private:
//     pthread_mutex_t mutex;
//     pthread_cond_t cond;
//     int value;


// #ifdef DEBUG        
//     Logger logger;
// #endif

    
// };



// #endif // TABLE_HPP