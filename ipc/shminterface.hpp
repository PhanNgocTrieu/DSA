#ifndef SHM_INTERFACE_H
#define SHM_INTERFACE_H

#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DEFAULT_SHM_FILE "/tmp/shm_default"

class shm {
    public:
        virtual ~shm() {}
        virtual void init_shm(const std::string& shm_file = DEFAULT_SHM_FILE) {
            unique_key = ftok(shm_file.c_str(), IPC_CREAT);
            shm_id = shmget(unique_key, )
        }

        virtual void write_shm(const std::string& message) {

        }

        virtual std::string read_shm_message() {

        }

        virtual void detach_shm() {

        }

    protected:
        key_t unique_key;
        std::string shm_file;
        int shm_id;
};

#endif