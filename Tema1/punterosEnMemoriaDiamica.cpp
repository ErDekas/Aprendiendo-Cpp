#include <iostream>

using namespace std;

int main() {
    int *p = new int; // Reserva memoria para un puntero
    *p = 20; // Almacena 20 en esa dirección
    cout << *p; // Muestra 20
    delete p; // Libera la memoria asignada
}