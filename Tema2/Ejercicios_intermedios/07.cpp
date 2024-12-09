#include <iostream>
#include <string>

using namespace std;

class Fraccion {
private:
    double numerador;
    double denominador;

public:
    // Constructor
    Fraccion(double _numerador, double _denominador) {
        numerador = _numerador;
        denominador = _denominador;
        if (denominador == 0) {
            throw invalid_argument("El denominador no puede ser cero.");
        }
    }

    // Método para sumar fracciones
    Fraccion sumar(const Fraccion& otra) const {
        double nuevoNumerador = numerador * otra.denominador + otra.numerador * denominador;
        double nuevoDenominador = denominador * otra.denominador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }

    // Método para restar fracciones
    Fraccion restar(const Fraccion& otra) const {
        double nuevoNumerador = numerador * otra.denominador - otra.numerador * denominador;
        double nuevoDenominador = denominador * otra.denominador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }

    // Método para multiplicar fracciones
    Fraccion multiplicar(const Fraccion& otra) const {
        double nuevoNumerador = numerador * otra.numerador;
        double nuevoDenominador = denominador * otra.denominador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }

    // Método para dividir fracciones
    Fraccion dividir(const Fraccion& otra) const {
        if (otra.numerador == 0) {
            throw invalid_argument("No se puede dividir por una fracción con numerador cero.");
        }
        double nuevoNumerador = numerador * otra.denominador;
        double nuevoDenominador = denominador * otra.numerador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }
    // Mostrar fracción
    void mostrar() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
        Fraccion f1(3, 4);
        Fraccion f2(2, 5);

        Fraccion suma = f1.sumar(f2);
        Fraccion resta = f1.restar(f2);
        Fraccion producto = f1.multiplicar(f2);
        Fraccion cociente = f1.dividir(f2);

        cout << "Suma: ";
        suma.mostrar();

        cout << "Resta: ";
        resta.mostrar();

        cout << "Producto: ";
        producto.mostrar();

        cout << "Cociente: ";
        cociente.mostrar();

    return 0;
}
