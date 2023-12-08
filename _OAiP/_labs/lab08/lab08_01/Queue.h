#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* array;
    int front;
    int rear;
    int maxSize;
public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    void print();
};

#endif