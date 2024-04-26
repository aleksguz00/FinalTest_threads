#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <chrono>

std::shared_mutex mtx;
int data = 0;

void Writer() {
    for (int i = 1; i <= 5; ++i) {
        mtx.lock_shared();
        data = i;
        std::cout << "Writer thread writes: " << data << std::endl;
        mtx.unlock_shared();
    }
}

void Reader() {
    for (int i = 1; i <= 5; ++i) {
        mtx.lock_shared();
        std::cout << "Reader thread reads: " << data << std::endl;
        mtx.unlock_shared();
    }
}

int main() {
    std::thread t1(Writer);
    std::thread t2(Reader);

    t1.join();
    t2.join();
}