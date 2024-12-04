#include <iostream>

using namespace std;

int incrementar(int x){
    x = x + 1; // Cambia solo la copia local
}

int main() {
    int numero = 5;
    incrementar(5); // La copia de número se modifica no el original
    cout << numero << endl; // Muestra 5
    return 0;
}