#include <iostream>
using namespace std;

// Clase que representa un nodo de la lista doble.
class Nodo {
public:
    int dato; // Dato que almacena el nodo.
    Nodo* siguiente; // Puntero al siguiente nodo.
    Nodo* anterior; // Puntero al nodo anterior.

    // Constructor para inicializar el nodo.
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

// Clase para gestionar la lista doble.
class ListaDoble {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista.

public:
    // Constructor para inicializar la lista vacía.
    ListaDoble() {
        cabeza = nullptr;
    }

    // Método para agregar un nodo al final de la lista.
    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor); // Crear un nuevo nodo.
        if (cabeza == nullptr) {
            cabeza = nuevo; // Si la lista está vacía, el nuevo nodo es la cabeza.
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente; // Recorremos hasta el último nodo.
            }
            actual->siguiente = nuevo; // Conectamos el último nodo al nuevo nodo.
            nuevo->anterior = actual; // El nuevo nodo apunta al nodo anterior.
        }
    }

    // Método para imprimir los elementos de la lista.
    void imprimir() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " <-> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    // Destructor para liberar memoria de los nodos.
    ~ListaDoble() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaDoble lista;
    lista.agregarFinal(10);
    lista.agregarFinal(20);
    lista.agregarFinal(30);

    cout << "Elementos de la lista doble:" << endl;
    lista.imprimir();

    return 0;
}