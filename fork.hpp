#ifndef FORK_HPP
#define FORK_HPP
#include <pthread.h>
#include <iostream>


#include <vector>
#include <fstream>
#include <sys/time.h>

#include "utils.hpp"

using namespace std;




class Fork {
public:
    Fork(int id);
    void wait(int phr_id);
    void signal(int phr_id); 
    ~Fork();

    // void add_log(string s);
    // void write_log();

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;

    int id;
    // vector<string> log_array;
    Logger logger;
};



#endif // FORK_HPP