#include<iostream>
#include<sys/time.h>
using namespace std;

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}



int main()
{
    
    cout << timeInMilliseconds();
    return 0;
}