


#include "utils.hpp"


#ifndef FORK_HPP
#define FORK_HPP

#include <pthread.h>
#include <iostream>


class Fork {
public:
    Fork(int id );
    void wait(int phr_id);

    void signal(int phr_id); 

    int draw_tk(){
        // assume a philosopher won't call it second time
                           // before its first tk expires.
        
        // pthread_mutex_lock(&mutex_tk);
        int tmp = tk_next;
        tk_next = (tk_next + 1) % n_tk_max;
        // pthread_mutex_unlock(&mutex_tk);

        return tmp;
    }

    ~Fork();

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;

    // pthread_mutex_t mutex_tk;
    int tk_serving;
    int n_tk_max;
    int tk_next;
 
    int id;
    Logger logger;    
};

#endif