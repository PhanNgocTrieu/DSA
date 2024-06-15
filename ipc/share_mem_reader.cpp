#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;
#ifdef FUNCTION_SHM
namespace shm_funs {
    struct key_t;
    // ftok(): generate a unique key
    key_t ftok();
    // shmget(): Upon successful completion, shmget() returns an identifier for the shared memory segment.
    int shmget(key_t key,size_t size, int shmflg);
    // Before you can use a shared memory segment, you have to attach yourself to it using shmat(). 
    // Here, shmid is a shared memory ID and shmaddr specifies the specific address to use but we should set it to zero and OS will automatically choose the address.
    void *shmat(int shmid ,void *shmaddr ,int shmflg);
    // When you’re done with the shared memory segment, your program should detach itself from it using shmdt().
    int shmdt(void *shmaddr);
    // When you detach from shared memory, it is not destroyed. So, to destroy shmctl() is used.
    shmctl(int shmid,IPC_RMID,NULL);
};
#endif

int main() {
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);
 
 
    cout << "Data read in memory: " << str << endl;
 
    // detach from shared memory
    shmdt(str);
    // destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}