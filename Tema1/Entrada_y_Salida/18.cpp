#include <iostream>

using namespace std;
int main() {
    int numero;
    cout << "Introduce un número entero" << endl;
    cin >> numero;
    int tamano = 0;
    if(numero == 0) {
        tamano == 1;
    } else {

        if(numero < 0){
        numero = -numero;
        }
        while(numero > 0){
            numero /= 10;
            tamano++;
        }
    }
    cout << "El tamañao de dígitos del número es: " << tamano << endl;
}