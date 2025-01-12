#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregarAlFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void insertarEnPosicion(int valor, int posicion) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (posicion == 0) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            for (int i = 0; i < posicion - 1 && temp != nullptr; ++i) {
                temp = temp->siguiente;
            }
            if (temp != nullptr) {
                nuevoNodo->siguiente = temp->siguiente;
                temp->siguiente = nuevoNodo;
            } else {
                std::cerr << "Posición fuera de rango" << std::endl;
                delete nuevoNodo;
            }
        }
    }

    void mostrarElementos() const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~ListaEnlazada() {
        Nodo* temp;
        while (cabeza != nullptr) {
            temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaEnlazada lista;
    lista.agregarAlFinal(1);
    lista.agregarAlFinal(2);
    lista.agregarAlFinal(3);
    lista.mostrarElementos();

    lista.insertarEnPosicion(4, 1);
    lista.mostrarElementos();

    lista.insertarEnPosicion(5, 0);
    lista.mostrarElementos();

    lista.insertarEnPosicion(6, 10); // Posición fuera de rango

    return 0;
}