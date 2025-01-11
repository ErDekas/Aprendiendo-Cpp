/* Las colas son estructuras de datos que siguen el principio FIFO 
(First In, First Out), es decir, el primer elemento en entrar es el primero en salir.)
*/
#include <iostream>
#include <queue>

int main() {
    // Crear una cola de enteros
    std::queue<int> q;

    // Insertar elementos en la cola
    q.push(10);
    q.push(20);
    q.push(30);

    // Mostrar el elemento en el frente de la cola
    std::cout << "El elemento en el frente de la cola es: " << q.front() << std::endl;

    // Eliminar el elemento en el frente de la cola
    q.pop();

    // Mostrar el nuevo elemento en el frente de la cola
    std::cout << "El nuevo elemento en el frente de la cola es: " << q.front() << std::endl;

    // Mostrar todos los elementos de la cola
    std::cout << "Elementos en la cola: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}

/* Explicación del código:
Inclusión de la biblioteca <queue>: 
Esta biblioteca proporciona la clase std::queue que se utiliza para crear colas en C++.
Creación de una cola: std::queue<int> q; crea una cola de enteros.
Inserción de elementos: q.push(valor); inserta elementos en la cola.
Acceso al frente de la cola: q.front(); 
devuelve el elemento en el frente de la cola sin eliminarlo.
Eliminación del frente de la cola: q.pop(); 
elimina el elemento en el frente de la cola.
Recorrido de la cola: 
Se utiliza un bucle while (!q.empty()) para mostrar y 
eliminar todos los elementos de la cola. */