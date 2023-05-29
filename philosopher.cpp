#include "philosopher.hpp"
#include <iostream>
#include <string> 

using namespace std;



Philosopher::Philosopher(int id, Fork *leftFork, Fork *rightFork, Table *table) :id(id), cancelled(false), leftFork(leftFork), rightFork(rightFork), table(table) {
    srand((unsigned) time(&t1));

}

void Philosopher::start() {
    // TODO: start a philosopher thread

    pthread_create(&t, NULL, run, (void *)this);
}


int Philosopher::join() {
    // TODO: join a philosopher thread
    pthread_join(t, NULL);
}

int Philosopher::cancel() {
    // TODO: cancel a philosopher thread
    pthread_cancel(t);
}



void Philosopher::think() {
    int thinkTime = rand() % (MAXTHINKTIME - MINTHINKTIME) + MINTHINKTIME;

    // string s = "think-" + int2string(thinkTime) + "_sec";
    // col_print(s, id, COL_WIDTH, PHILOSOPHERS);

    sleep(thinkTime);
}


void Philosopher::eat() {
    
    enter();

    pickup(id);

    sleep(EATTIME);

    putdown(id);

    leave();
}


void Philosopher::pickup(int id) {
    // TODO: implement the pickup interface, the philosopher needs to pick up the left fork first, then the right fork

    leftFork->wait(id);


    rightFork->wait(id);
}

void Philosopher::putdown(int id) {
    // TODO: implement the putdown interface, the philosopher needs to put down the left fork first, then the right fork

    leftFork->signal(id);
        
    rightFork->signal(id);
}

void Philosopher::enter() {
    // TODO: implement the enter interface, the philosopher needs to join the table first
    table->wait(id);
}

void Philosopher::leave() {
    // TODO: implement the leave interface, the philosopher needs to let the table know that he has left
    table->signal(id);
}


void* Philosopher::run(void* arg) {
    // TODO: complete the philosopher thread routine. 

    Philosopher *p = (Philosopher *)arg;

    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (1) {

        p->think(); 

        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

        p->eat();

        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    }

    return NULL;
}