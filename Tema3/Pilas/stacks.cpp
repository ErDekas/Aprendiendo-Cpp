#include <iostream>
#include <stack>

int main() {
    // Una pila (stack) es una estructura de datos que sigue el principio LIFO (Last In, First Out)
    // Esto significa que el último elemento en entrar es el primero en salir

    std::stack<int> pila;

    // Agregar elementos a la pila
    pila.push(10);
    pila.push(20);
    pila.push(30);

    // Mostrar el elemento en la parte superior de la pila
    std::cout << "Elemento en la parte superior: " << pila.top() << std::endl;

    // Eliminar el elemento en la parte superior de la pila
    pila.pop();

    // Mostrar el nuevo elemento en la parte superior de la pila
    std::cout << "Nuevo elemento en la parte superior: " << pila.top() << std::endl;

    // Verificar si la pila está vacía
    if (pila.empty()) {
        std::cout << "La pila está vacía" << std::endl;
    } else {
        std::cout << "La pila no está vacía" << std::endl;
    }

    // Mostrar el tamaño de la pila
    std::cout << "Tamaño de la pila: " << pila.size() << std::endl;

    return 0;
}