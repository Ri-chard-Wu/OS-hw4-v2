
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





#define COL_WIDTH 15


void col_print(string s, int col_id, int w, int n_col){

    string s_out = "";
    
    for(int i = 0; i < col_id; i++){
        s_out += "|";
        s_out.append(w - 1, ' ');
    }
    
    int len_i = s_out.length();
    s_out += "|";
    s_out += s;
    int diff = s_out.length() - len_i;
    s_out.append(w - diff, ' ');

    for(int i = col_id + 1; i < n_col; i++){
        s_out += "|";
        s_out.append(w - 1, ' ');
    }
    
    s_out += "\n";
    cout << s_out;
}
