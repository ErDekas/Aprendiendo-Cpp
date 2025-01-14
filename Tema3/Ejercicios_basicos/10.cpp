#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue; // Puntero al array que representará la cola
    int front;  // Índice del frente de la cola
    int rear;   // Índice del final de la cola
    int size;   // Tamaño máximo de la cola
    int count;  // Número actual de elementos en la cola

public:
    // Constructor
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Método para añadir un elemento a la cola (enqueue)
    bool enqueue(int value) {
        if (isFull()) {
            cout << "Error: La cola está llena.\n";
            return false;
        }
        rear = (rear + 1) % size; // Calcular la nueva posición del final
        queue[rear] = value;
        count++;
        return true;
    }

    // Método para eliminar un elemento de la cola (dequeue)
    bool dequeue() {
        if (isEmpty()) {
            cout << "Error: La cola está vacía.\n";
            return false;
        }
        front = (front + 1) % size; // Calcular la nueva posición del frente
        count--;
        return true;
    }

    // Método para obtener el elemento al frente de la cola
    int frontElement() {
        if (isEmpty()) {
            cout << "Error: La cola está vacía.\n";
            return -1; // Retornar un valor indicador de error
        }
        return queue[front];
    }

    // Método para verificar si la cola está vacía
    bool isEmpty() {
        return count == 0;
    }

    // Método para verificar si la cola está llena
    bool isFull() {
        return count == size;
    }

    // Método para imprimir el contenido de la cola
    void display() {
        if (isEmpty()) {
            cout << "La cola está vacía.\n";
            return;
        }
        cout << "Contenido de la cola: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % size] << " ";
        }
        cout << endl;
    }
};

// Ejemplo de uso
int main() {
    CircularQueue cq(5); // Crear una cola circular con tamaño 5

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cq.dequeue();
    cq.display();

    cout << "Elemento al frente: " << cq.frontElement() << endl;

    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();

    return 0;
}
