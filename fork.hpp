#ifndef FORK_HPP
#define FORK_HPP

#include <pthread.h>
#include <iostream>

#include <vector>
#include <fstream>
using namespace std;
class Fork {
public:
    Fork(int id);
    void wait(int phr_id);
    void signal(int phr_id); 
    
    void add_log(string s);
    void write_log();

    ~Fork();
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int value;
    int id;

    vector<string> log_array;
};



#endif // FORK_HPP