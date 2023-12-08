#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(int size) {
    array = new int[size];
    front = 0;
    rear = -1;
    maxSize = size;
}

Queue::~Queue() {
    delete[] array;
}

bool Queue::isEmpty() {
    return rear < front;
}

bool Queue::isFull() {
    return rear == maxSize - 1;
}

void Queue::enqueue(int value)
{
if (isFull()) {
    cout << "Queue is full." << endl;
}
else {
    rear++;
    array[rear] = value;
}
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return 0;
    }
    else {
        int value = array[front];
        front++;
        return value;
    }
}

void Queue::print() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    }
    else {
        for (int i = front; i <= rear; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}