#include <iostream>
#include <stdexcept>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(int value) {
        if (topIndex >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack desbordado");
        }
        arr[++topIndex] = value;
    }

    void pop() {
        if (topIndex < 0) {
            throw std::underflow_error("Stack subdesbordado");
        }
        --topIndex;
    }

    int top() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack vacio");
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Elemento superior: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Elemento superior después del pop es: " << stack.top() << std::endl;

    return 0;
}