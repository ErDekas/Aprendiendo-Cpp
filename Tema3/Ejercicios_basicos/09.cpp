#include <iostream>
#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int size;

public:
    Queue() : frontIndex(0), rearIndex(-1), size(0) {}

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Cola llena\n";
            return;
        }
        rearIndex = (rearIndex + 1) % MAX_SIZE;
        arr[rearIndex] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Cola vacía\n";
            return;
        }
        frontIndex = (frontIndex + 1) % MAX_SIZE;
        size--;
    }

    int front() {
        if (isEmpty()) {
            std::cout << "Cola vacía\n";
            return -1;
        }
        return arr[frontIndex];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Elemento frontal es: " << q.front() << std::endl;
    q.dequeue();
    std::cout << "Elemento frontal es: " << q.front() << std::endl;

    return 0;
}