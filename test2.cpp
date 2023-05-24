#include<iostream>
#include <stdio.h>

using namespace std;


int main()
{
    
#ifdef TEST_MACRO
    printf("defined\n");
#else
    printf("not defined\n");
#endif

    return 0;
}