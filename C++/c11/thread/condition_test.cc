#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;

void producer1() {
    for (int i = 1; i <= 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one();  // 唤醒消费者
    }
}

void consumer1() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !q.empty(); });  // 等待生产者
        int item = q.front();
        q.pop();
        std::cout << "Consumed: " << item << std::endl;
    }
}


void producer2() {
    for (int i = 1; i <= 5; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
        cv.notify_one();  // 唤醒一个消费者
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void consumer2() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !q.empty(); });  // 等待队列非空
        int item = q.front();
        q.pop();
        std::cout << "Consumed: " << item << std::endl;
    }
}

int main() {
    // test1
    std::thread p(producer1);
    std::thread c(consumer1);
    p.join();
    c.join();

    // test2
    // std::thread p(producer2);
    // std::thread c(consumer2);
    // p.join();
    // c.join();

    return 0;
}

