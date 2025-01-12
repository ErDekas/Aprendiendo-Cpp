#include <iostream>
using namespace std;

// Nodo básico del árbol binario
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Insertar un nuevo valor en el árbol binario
Nodo* insertar(Nodo* raiz, int valor) {
    if (!raiz) return new Nodo(valor); // Caso base: insertar como nodo raíz

    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor); // Insertar en el subárbol izquierdo
    } else {
        raiz->derecha = insertar(raiz->derecha, valor); // Insertar en el subárbol derecho
    }

    return raiz; // Retornar la raíz sin cambios
}

// Imprimir en orden
void imprimirEnOrden(Nodo* raiz) {
    if (!raiz) return;
    imprimirEnOrden(raiz->izquierda);
    cout << raiz->valor << " ";
    imprimirEnOrden(raiz->derecha);
}

int main() {
    Nodo* raiz = nullptr;

    // Insertamos valores
    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 5);
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 3);
    raiz = insertar(raiz, 7);

    // Imprimir el árbol en orden
    cout << "Árbol Binario en orden: ";
    imprimirEnOrden(raiz);

    return 0;
}
