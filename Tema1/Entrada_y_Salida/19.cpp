#include <iostream>

using namespace std;

int main() {
    int numero;
    int mayor = 0;

    cout << "Dime un número entero" << endl;
    cin >> numero;
    int numero_copia = numero;

    if(numero < 0) {
        numero = -numero;
    }
    
    while(numero > 0) {
        int digito = numero % 10;
        if(digito > mayor){
            mayor = digito;
        }
        numero /= 10;
    }
    cout << "El dígito más grande de: " << numero_copia << " es: " << mayor << endl;
    return 0;
}