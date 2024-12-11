#include <iostream>
#include <string>

using namespace std;

class Empleado {
public:
    string nombre;
    double salarioBase;
};

class Gerente : public Empleado {
public:
    Gerente(string _nombre, double _salarioBase) {
        nombre = _nombre;
        salarioBase = _salarioBase;
    }
    double calcularSalario() {
        return salarioBase * 1.21;
    }
    void nombrar() {
        cout << "Hola, " << nombre << " has cobrado: ";
    }
};

class Programador : public Empleado {
public:
    Programador(string _nombre, double _salarioBase) {
        nombre = _nombre;
        salarioBase = _salarioBase;
    }
    double calcularSalario() {
        return salarioBase + 1000;
    }
    void nombrar() {
        cout << "Hola, " << nombre << " has cobrado ";
    }
};

int main() {
    Gerente g1("Paco", 1500);
    g1.nombrar();
    cout << g1.calcularSalario() << endl;
    Programador p1("Pablo", 1500);
    p1.nombrar();
    cout << p1.calcularSalario() << endl;
    return 0;
}