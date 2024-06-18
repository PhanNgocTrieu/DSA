#include "shminterface.hpp"

int main() {
    ShmWriter writer;
    writer.init_shm();
    writer.write_shm("Hello");
    scanf("\n");
    return 0;
}