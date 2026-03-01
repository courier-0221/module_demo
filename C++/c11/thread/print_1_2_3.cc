#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int turn = 1;  // 1: 线程1, 2: 线程2, 3: 线程3
const int LOOP_COUNT = 5;

void print(int id) {
    for (int i = 0; i < LOOP_COUNT; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [id] { return turn == id; });  // 等待轮到自己
        std::cout << id << std::endl;
        turn = (turn % 3) + 1;  // 轮换到下一个线程
        cv.notify_all();  // 唤醒其他线程
    }
}

int main() {
    std::thread t1(print, 1);
    std::thread t2(print, 2);
    std::thread t3(print, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
