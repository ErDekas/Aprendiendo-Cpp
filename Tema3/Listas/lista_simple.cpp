#include <iostream>
using namespace std;

// Clase que representa un nodo de la lista simple.
class Nodo {
public:
    int dato; // Dato que almacena el nodo.
    Nodo* siguiente; // Puntero al siguiente nodo en la lista.

    // Constructor para inicializar el nodo.
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr; // Por defecto, el puntero apunta a nullptr.
    }
};

// Clase para gestionar la lista simple.
class ListaSimple {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista.

public:
    // Constructor para inicializar la lista vacía.
    ListaSimple() {
        cabeza = nullptr;
    }

    // Método para agregar un nodo al inicio de la lista.
    void agregarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor); // Crear un nuevo nodo.
        nuevo->siguiente = cabeza; // El nuevo nodo apunta al nodo que era la cabeza.
        cabeza = nuevo; // Actualizamos la cabeza al nuevo nodo.
    }

    // Método para imprimir los elementos de la lista.
    void imprimir() {
        Nodo* actual = cabeza; // Usamos un puntero para recorrer la lista.
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente; // Avanzamos al siguiente nodo.
        }
        cout << "NULL" << endl;
    }

    // Destructor para liberar memoria de los nodos.
    ~ListaSimple() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza; // Guardamos el nodo actual.
            cabeza = cabeza->siguiente; // Avanzamos al siguiente nodo.
            delete temp; // Liberamos la memoria del nodo actual.
        }
    }
};

int main() {
    ListaSimple lista;
    lista.agregarInicio(10);
    lista.agregarInicio(20);
    lista.agregarInicio(30);

    cout << "Elementos de la lista simple:" << endl;
    lista.imprimir();

    return 0;
}