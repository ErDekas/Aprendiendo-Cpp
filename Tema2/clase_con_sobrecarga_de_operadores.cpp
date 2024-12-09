/*
Sobrecarga de operadores:
Puedes redefinir operadores como +, -, o == 
para que funcionen con tus clases
*/

#include <iostream>
#include <string>

using namespace std;

class Fraccion {
public:
    int numerador, denominador;

    Fraccion(int num, int den) : numerador(num), denominador(den) {}

    Fraccion operator+(const Fraccion &f) {
        return Fraccion(numerador * f.denominador + f.numerador * denominador, denominador * f.denominador);
    }

    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    Fraccion f1(1,2), f2(1,3);
    Fraccion resultado = f1 + f2;
    resultado.imprimir(); // Muestra 5/6
    
    return 0;
}