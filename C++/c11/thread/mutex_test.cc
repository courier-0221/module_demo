#include <thread>
#include <iostream>
#include <mutex>

std::mutex mtx;

int count = 0;

void func_no_mutex() {
    for (int i = 0; i < 100000; ++i) {
        count++;
    }
}

void func_yes_mutex() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        count++;
    }
}

int main(void) {

    // std::thread t1(func_no_mutex);
    // std::thread t2(func_no_mutex);

    std::thread t1(func_yes_mutex);
    std::thread t2(func_yes_mutex);

    t1.join();
    t2.join();

    printf("count:%d\n", count);

    return 0;
}