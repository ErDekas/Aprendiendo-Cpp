#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Representación del heap en un vector

    // Función para mantener la propiedad del heap al subir un nodo
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; // Índice del nodo padre
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]); // Intercambiar si el hijo es mayor que el padre
                index = parent; // Continuar con el nuevo índice
            } else {
                break;
            }
        }
    }

    // Función para mantener la propiedad del heap al bajar un nodo
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;  // Índice del hijo izquierdo
            int right = 2 * index + 2; // Índice del hijo derecho
            int largest = index;      // Suponemos que el índice actual es el mayor

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]); // Intercambiar y continuar bajando
                index = largest;
            } else {
                break; // Salir si el índice actual ya es el mayor
            }
        }
    }

public:
    // Insertar un elemento en la cola de prioridad
    void insert(int value) {
        heap.push_back(value);       // Añadir el nuevo elemento al final del vector
        heapifyUp(heap.size() - 1); // Ajustar la posición del elemento
    }

    // Extraer el elemento de mayor prioridad (máximo)
    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Error: La cola de prioridad está vacía.");
        }
        int maxElement = heap[0];      // Obtener el elemento máximo (raíz del heap)
        heap[0] = heap.back();         // Reemplazar la raíz con el último elemento
        heap.pop_back();               // Eliminar el último elemento
        heapifyDown(0);                // Ajustar la posición del nuevo elemento
        return maxElement;
    }

    // Obtener el elemento de mayor prioridad sin eliminarlo
    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Error: La cola de prioridad está vacía.");
        }
        return heap[0]; // La raíz del heap es el elemento máximo
    }

    // Verificar si la cola de prioridad está vacía
    bool isEmpty() {
        return heap.empty();
    }

    // Mostrar el contenido del heap (para depuración)
    void display() {
        cout << "Contenido del heap: ";
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

// Ejemplo de uso
int main() {
    PriorityQueue pq;

    // Insertar elementos
    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(25);

    pq.display();

    // Obtener el máximo
    cout << "Máximo: " << pq.getMax() << endl;

    // Extraer elementos de mayor prioridad
    cout << "Extraer máximo: " << pq.extractMax() << endl;
    pq.display();

    cout << "Extraer máximo: " << pq.extractMax() << endl;
    pq.display();

    return 0;
}
