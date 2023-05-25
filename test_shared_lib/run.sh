
rm *.so
rm *.o
rm main

gcc -g -fPIC -c mylib.c
gcc -shared mylib.o -o libmylib.so


g++ -g -o main main.cpp libmylib.so
g++ -g -o main main.cpp -lmylib -L.

LD_LIBRARY_PATH=. ./main