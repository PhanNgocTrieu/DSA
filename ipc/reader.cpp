#include "shminterface.hpp"

int main() {
    shm reader(shm::Host::READER);
    reader.init_shm();
    reader.read_shm_message();
    scanf("\n");
    return 0;
}