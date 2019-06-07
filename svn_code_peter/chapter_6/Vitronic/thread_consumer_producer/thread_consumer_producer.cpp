// thread_consumer_producer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

struct BoundedBuffer {
    int* buffer;
    int capacity;

    int front;
    int rear;
    int count;

    std::mutex lock;

    std::condition_variable not_full;
    std::condition_variable not_empty;

    BoundedBuffer(int capacity) : capacity(capacity), front(0), rear(0), count(0) {
        buffer = new int[capacity];
    }

    ~BoundedBuffer() {
        delete[] buffer;
    }

    void deposit(int data) {
        std::unique_lock<std::mutex> l(lock);

        not_full.wait(l, [this]() {return count != capacity; });

        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        ++count;

        l.unlock();
        not_empty.notify_one();
    }

    int fetch() {
        std::unique_lock<std::mutex> l(lock);

        not_empty.wait(l, [this]() {return count != 0; });

        int result = buffer[front];
        front = (front + 1) % capacity;
        --count;

        l.unlock();
        not_full.notify_one();

        return result;
    }
};


void consumer(int id, BoundedBuffer& buffer) {
    for (int i = 0; i < 50; ++i) {
        int value = buffer.fetch();
        std::cout << "Consumer " << id << " fetched " << value << std::endl;
        std::this_thread::sleep_for(500ms);
    }
}

void producer(int id, BoundedBuffer& buffer) {
    for (int i = 0; i < 75; ++i) {
        buffer.deposit(i);
        std::cout << "Produced " << id << " produced " << i << std::endl;
        std::this_thread::sleep_for(200ms);
    }
}

int main() {
    BoundedBuffer buffer(200);

    std::thread c1(consumer, 0, std::ref(buffer));
    std::thread c2(consumer, 1, std::ref(buffer));
    std::thread c3(consumer, 2, std::ref(buffer));
    std::thread c4(consumer, 3, std::ref(buffer));
    std::thread c5(consumer, 4, std::ref(buffer));
    std::thread c6(consumer, 5, std::ref(buffer));
    std::thread p1(producer, 0, std::ref(buffer));
    std::thread p2(producer, 1, std::ref(buffer));
    std::thread p3(producer, 2, std::ref(buffer));
    std::thread p4(producer, 3, std::ref(buffer));

    c1.join();
    c2.join();
    c3.join();
    c4.join();
    c5.join();
    c6.join();
    p1.join();
    p2.join();
    p3.join();
    p4.join();

    return 0;
}
