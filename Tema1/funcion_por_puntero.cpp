#include <iostream>

using namespace std;

void incrementar(int *x) {
    *x = *x + 1; // Cambia el valor original al que apunta el puntero
}

int main() {
    int numero = 5;
    incrementar(&numero); // Pasamos la dirección de número
    cout << numero << endl; // Muestra 6
    return 0;
}