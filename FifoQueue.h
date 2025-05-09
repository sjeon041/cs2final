#pragma once
#include <stdexcept>

template<typename T, int SIZE>
class FIFOQueue {
private:
    T data[SIZE];
    int front = 0;
    int rear = 0;
    int count = 0;

public:
    bool enqueue(T item) {
        if (count == SIZE) return false;
        data[rear] = item;
        rear = (rear + 1) % SIZE;
        count++;
        return true;
    }

    T dequeue() {
        if (count == 0) throw std::runtime_error("Queue underflow");
        T item = data[front];
        front = (front + 1) % SIZE;
        count--;
        return item;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == SIZE; }
};
