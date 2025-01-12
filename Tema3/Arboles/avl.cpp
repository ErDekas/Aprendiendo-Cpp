#include <iostream>
using namespace std;

// Estructura del nodo del árbol AVL
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

// Función para obtener la altura de un nodo
int obtenerAltura(Nodo* nodo) {
    return nodo ? nodo->altura : 0;
}

// Función para calcular el factor de balance
int obtenerFactorBalance(Nodo* nodo) {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

// Rotación simple a la derecha
Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;

    // Realizamos la rotación
    x->derecha = y;
    y->izquierda = T2;

    // Actualizamos las alturas
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x; // Nuevo nodo raíz
}

// Rotación simple a la izquierda
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;

    // Realizamos la rotación
    y->izquierda = x;
    x->derecha = T2;

    // Actualizamos las alturas
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y; // Nuevo nodo raíz
}

// Inserción en un árbol AVL
Nodo* insertar(Nodo* nodo, int valor) {
    // Caso base: insertar como una hoja
    if (!nodo) return new Nodo(valor);

    // Insertar en el subárbol izquierdo o derecho según el valor
    if (valor < nodo->valor) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->valor) {
        nodo->derecha = insertar(nodo->derecha, valor);
    } else {
        return nodo; // No permitimos valores duplicados
    }

    // Actualizar la altura del nodo actual
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    // Verificar el balance del nodo
    int balance = obtenerFactorBalance(nodo);

    // Caso 1: Rotación derecha (izquierda-izquierda)
    if (balance > 1 && valor < nodo->izquierda->valor) {
        return rotarDerecha(nodo);
    }

    // Caso 2: Rotación izquierda (derecha-derecha)
    if (balance < -1 && valor > nodo->derecha->valor) {
        return rotarIzquierda(nodo);
    }

    // Caso 3: Rotación izquierda-derecha
    if (balance > 1 && valor > nodo->izquierda->valor) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    // Caso 4: Rotación derecha-izquierda
    if (balance < -1 && valor < nodo->derecha->valor) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo; // Nodo sin cambios
}

// Imprimir el árbol en orden
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
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 25);

    // Imprimir el árbol en orden
    cout << "Árbol AVL en orden: ";
    imprimirEnOrden(raiz);

    return 0;
}
