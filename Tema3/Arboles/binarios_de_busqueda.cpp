#include <iostream>
using namespace std;

// Nodo del árbol binario de búsqueda
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Insertar un nuevo nodo en el árbol BST
Nodo* insertar(Nodo* raiz, int valor) {
    if (!raiz) return new Nodo(valor); // Caso base

    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor); // Subárbol izquierdo
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor); // Subárbol derecho
    }

    return raiz; // Retornamos la raíz sin cambios
}

// Buscar un valor en el árbol
bool buscar(Nodo* raiz, int valor) {
    if (!raiz) return false; // Valor no encontrado

    if (valor == raiz->valor) return true; // Valor encontrado

    if (valor < raiz->valor) {
        return buscar(raiz->izquierda, valor); // Buscar en el subárbol izquierdo
    } else {
        return buscar(raiz->derecha, valor); // Buscar en el subárbol derecho
    }
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
    raiz = insertar(raiz, 8);
    raiz = insertar(raiz, 3);
    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 1);
    raiz = insertar(raiz, 6);

    // Buscar un valor
    int valorBuscado = 7;
    cout << "¿El valor " << valorBuscado << " está en el árbol? " 
         << (buscar(raiz, valorBuscado) ? "Sí" : "No") << endl;

    // Imprimir el árbol en orden
    cout << "Árbol BST en orden: ";
    imprimirEnOrden(raiz);

    return 0;
}
