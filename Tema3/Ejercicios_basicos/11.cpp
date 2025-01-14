#include <iostream>
using namespace std;

// Nodo de la lista enlazada
struct Node {
    int data;        // Dato almacenado en el nodo
    Node* next;      // Puntero al siguiente nodo

    // Constructor para inicializar un nodo
    Node(int value) : data(value), next(nullptr) {}
};

// Clase para representar la cola
class LinkedQueue {
private:
    Node* front;     // Puntero al primer elemento de la cola
    Node* rear;      // Puntero al último elemento de la cola

public:
    // Constructor
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    // Destructor para liberar la memoria de la lista enlazada
    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Método para agregar un elemento a la cola
    void enqueue(int value) {
        Node* newNode = new Node(value); // Crear un nuevo nodo
        if (isEmpty()) {
            front = rear = newNode; // Si la cola está vacía, ambos apuntan al nuevo nodo
        } else {
            rear->next = newNode; // Conectar el nuevo nodo al final de la cola
            rear = newNode;       // Actualizar el puntero `rear`
        }
    }

    // Método para eliminar un elemento de la cola
    void dequeue() {
        if (isEmpty()) {
            cout << "Error: La cola está vacía.\n";
            return;
        }
        Node* temp = front;        // Guardar el nodo del frente para liberarlo
        front = front->next;       // Avanzar el puntero del frente
        if (front == nullptr) {    // Si la cola está vacía después de eliminar
            rear = nullptr;        // Asegurarse de que `rear` también sea nullptr
        }
        delete temp;               // Liberar la memoria del nodo eliminado
    }

    // Método para obtener el elemento al frente de la cola
    int frontElement() {
        if (isEmpty()) {
            cout << "Error: La cola está vacía.\n";
            return -1; // Valor indicador de error
        }
        return front->data;
    }

    // Método para verificar si la cola está vacía
    bool isEmpty() {
        return front == nullptr;
    }

    // Método para imprimir el contenido de la cola
    void display() {
        if (isEmpty()) {
            cout << "La cola está vacía.\n";
            return;
        }
        Node* current = front;
        cout << "Contenido de la cola: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Ejemplo de uso
int main() {
    LinkedQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    cout << "Elemento al frente: " << queue.frontElement() << endl;

    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();

    return 0;
}
