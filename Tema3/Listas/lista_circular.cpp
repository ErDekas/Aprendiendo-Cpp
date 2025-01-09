#include <iostream>
using namespace std;

// Clase que representa un nodo de la lista circular.
class Nodo {
public:
    int dato; // Dato que almacena el nodo.
    Nodo* siguiente; // Puntero al siguiente nodo.

    // Constructor para inicializar el nodo.
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

// Clase para gestionar la lista circular.
class ListaCircular {
private:
    Nodo* ultimo; // Puntero al último nodo de la lista.

public:
    // Constructor para inicializar la lista vacía.
    ListaCircular() {
        ultimo = nullptr;
    }

    // Método para agregar un nodo al final de la lista.
    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (ultimo == nullptr) {
            ultimo = nuevo; // El nuevo nodo es el único nodo.
            ultimo->siguiente = ultimo; // Apunta a sí mismo.
        } else {
            nuevo->siguiente = ultimo->siguiente; // Nuevo apunta al primero.
            ultimo->siguiente = nuevo; // Último apunta al nuevo.
            ultimo = nuevo; // Actualizamos el último nodo.
        }
    }

    // Método para imprimir los elementos de la lista.
    void imprimir() {
        if (ultimo == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo* actual = ultimo->siguiente; // Empezamos en el primer nodo.
        do {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        } while (actual != ultimo->siguiente); // Continuamos hasta regresar al inicio.
        cout << "(inicio)" << endl;
    }

    // Destructor para liberar memoria de los nodos.
    ~ListaCircular() {
        if (ultimo != nullptr) {
            Nodo* actual = ultimo->siguiente;
            Nodo* temp;
            do {
                temp = actual;
                actual = actual->siguiente;
                delete temp;
            } while (actual != ultimo->siguiente);
        }
    }
};

int main() {
    ListaCircular lista;
    lista.agregarFinal(10);
    lista.agregarFinal(20);
    lista.agregarFinal(30);

    cout << "Elementos de la lista circular:" << endl;
    lista.imprimir();

    return 0;
}