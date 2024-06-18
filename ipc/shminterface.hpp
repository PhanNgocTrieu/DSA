#ifndef SHM_INTERFACE_H
#define SHM_INTERFACE_H

#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define DEFAULT_SHM_FILE "/tmp/shm_default"
#define DEFAULT_SHM_KEY 66

class shm {
    public:
        enum Host {
            WRITER = 0,
            READER
        }; 

    public:
        shm(const Host& h) : m_host(h) {}

        virtual ~shm() {
            if (m_host == Host::READER) {
                shmctl(shm_id, IPC_RMID, NULL);
            }
        }
        
        virtual void init_shm(const std::string& shm_file = DEFAULT_SHM_FILE) {
            unique_key = ftok(shm_file.c_str(), IPC_CREAT);
            shm_id = shmget(unique_key, 2048, 0x666 | IPC_CREAT);
        }

        virtual void write_shm(const std::string& message) {
            if (m_host != Host::WRITER) {
                std::cerr << "This role is not writer!" << std::endl;
                return;
            }
            char* buffer = (char*) shmat(shm_id, (void*)0, 0);
            buffer = (char*)message.c_str();
            detach_shm(buffer);
        }

        virtual std::string read_shm_message() {
            if (m_host != Host::READER) {
                std::cerr << "This role is not reader!" << std::endl;
                return std::string{""};
            }

            char* str = (char*) shmat(shm_id, (void*)0, 0);
            std::cout << "Data read in memory: " << str << std::endl;
            detach_shm(str);
            return std::string{} = str;
        }

    protected:
        virtual void detach_shm(const char* str) {
            shmdt(str);
        }

    protected:
        Host m_host = Host::WRITER;
        key_t unique_key;
        std::string shm_file;
        int shm_id;
};

class ShmReader : public shm {
    public:
        ShmReader(shm::Host h = shm::Host::READER) : 
        shm(h) {}   

};

class ShmWriter : public shm {
    public:
        ShmWriter(shm::Host h = shm::Host::WRITER) :
        shm(h) {}
};

#endif