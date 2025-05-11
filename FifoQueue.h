#pragma once
#include "global.h"
#include <stdexcept>
#include <iostream>

template<typename T, int SIZE>
class FIFOQueue {
private:
    T data[SIZE];
    int front = 0;
    int rear = 0;
    int count = 0;

public:
    int getCount(){
        return count;
    }
    bool enqueue(T item) {
        if (count == SIZE) return false;
        data[rear] = item;
        rear = (rear + 1) % SIZE; // Circular implementation.
        count++;
        return true;
    }

    T dequeue() {
        if (count == 0) throw std::runtime_error("Queue underflow"); // Quick error check to see if queue is empty.
        T item = data[front];
        front = (front + 1) % SIZE;
        count--;
        return item;
    }
    void printAll() const {
        if (count == 0) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "\n--- Orders in Queue ---\n";
        for (int i = 0; i < count; ++i) {
            int index = (front + i) % SIZE;
            cout << "Position in queue: " << i + 1 << std::endl;
            data[index].printOrder();
            cout << endl;
        }
    }
    void searchById(int id) const {
        bool found = false;

        for (int i = 0; i < count; ++i) {
            int index = (front + i) % SIZE;
            if (data[index].orderId == id) {
                std::cout << "\nOrder with ID #" << id << " found at position " << i + 1 << " in the queue:\n";
                data[index].printOrder();
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Order with ID #" << id << " not found in queue.\n";
        }
    }
    bool searchById(int id, bool dummy) const { // Slightly different implementation to facilitate the "Get Order by ID" command in main.
        bool found = false;

        for (int i = 0; i < count; ++i) {
            int index = (front + i) % SIZE;
            if (data[index].orderId == id) {
                std::cout << "\nOrder with ID #" << id << " found:\n";
                data[index].printOrder();
                return true;
            }
        }
        return found;
    }
    bool isEmpty() const { return count == 0; } // Quick check functions.
    bool isFull() const { return count == SIZE; }
};
