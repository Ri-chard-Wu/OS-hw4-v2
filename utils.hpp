#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sys/time.h>
#include <vector>
#include<stdio.h>
#include <fstream>
using namespace std;

long long get_time(void);


std::string ll2str(long long n);


class Logger{
public:    
    Logger();
    void add_meta(std::string s);
    void add_log(std::string msg);
    void write_log(char *filename);
    
    std::string meta;
    std::vector< std::string > log_array;
};


#endif