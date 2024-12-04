#include <iostream>

using namespace std;

void incrementar(int &x){
    x = x + 1; // Cambia el valor original
}

int main() {
    int numero = 5;
    incrementar(numero); // El valor original se incrementa
    cout << numero << endl; // Mostrará 6
    return 0;
}