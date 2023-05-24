
// #include <iostream>
// #include <sys/time.h>
// using namespace std;

#include "utils.hpp"


long long get_time(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}


string ll2str(long long n){
    char buf[20];
    sprintf(buf, "%lld", n);
    return ((string)buf);
}



 
Logger::Logger(){
    meta = "";
}

void Logger::add_meta(string s){
    if(meta == ""){
        meta = s;
    }
    else{
        meta = meta + " " + s;
    }
    
}

void Logger::add_log(string msg){
    msg = ll2str(get_time()) + ", " + msg;
    log_array.push_back(msg);
}

void Logger::write_log(char *filename){

    ofstream out(filename);
    out << meta + "\n";

    for(int i = 0; i < log_array.size(); i++){
        out << log_array[i] << "\n";
    }
    out.close();
}


