#include "philosopher.hpp"

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    // TODO: create forks, table, and philosophers. The number of forks and philosophers are defined in the config.hpp
    Fork *f[PHILOSOPHERS];
    for (int i = 0; i < PHILOSOPHERS; i++) {
        f[i] = new Fork(
#ifdef DEBUG        
            i
#endif            
        );
    }
    Table *table = new Table(PHILOSOPHERS);

    Philosopher* philosophers[PHILOSOPHERS];
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i] = new Philosopher(i, f[i], f[(i + 1) % PHILOSOPHERS], table);
    }

    // TODO: start running philosopher threads
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->start();
    }

    sleep(RUNTIME);

    // TODO: cancel philosopher threads 
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->cancel();
    }
    printf("All philosophers have been cancelled.\n");

    // TODO: join philosopher threads (i.e. wait for them to finish) 
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->join();
    }

    // TODO: delete forks, table, and philosophers
    for (int i = 0; i < PHILOSOPHERS; i++) {
        delete philosophers[i];
        delete f[i];
    }
    delete table;
    
    return 0;
}




// #include "philosopher.hpp"

// #include <stdlib.h>
// #include <unistd.h>
// #include <vector>
// using namespace std;

// int main(int argc, char** argv) {

//     // TODO: create forks, table, and philosophers. The number of forks and philosophers are defined in the config.hpp

//     Table *table = new Table(PHILOSOPHERS);
//     vector<Fork *> fork_array;
//     vector<Philosopher *> phr_array;

//     for (int i = 0; i < PHILOSOPHERS; i++){
//         fork_array.push_back(new Fork(
// #ifdef DEBUG        
//             i
// #endif
//             ));
//     }

//     for (int i = 0; i < PHILOSOPHERS; i++){
//         Fork *leftFork = fork_array[i];
//         Fork *rightFork = fork_array[(i + 1) % PHILOSOPHERS];
//         phr_array.push_back(new Philosopher(i, leftFork, rightFork, table));
//     }    
    

//     // TODO: start running philosopher threads
//     for (int i = 0; i < PHILOSOPHERS; i++){
//         phr_array[i]->start();
//     }    

//     sleep(RUNTIME);

//     // TODO: cancel philosopher threads 
//     for (int i = 0; i < PHILOSOPHERS; i++){
//         phr_array[i]->cancel();
//     } 

//     // TODO: join philosopher threads (i.e. wait for them to finish) 
//     for (int i = 0; i < PHILOSOPHERS; i++){
//         phr_array[i]->join();
//     } 

//     // TODO: delete forks, table, and philosophers
//     delete table;
//     for (int i = 0; i < PHILOSOPHERS; i++){
//         delete fork_array[i];
//         delete phr_array[i];
//     }
    
//     return 0;
// }