/*
Polimorfismo:
El polimorfismo permite que una función se comporte de manera diferente
según el tipo de objeto.

Funciones virtuales:
Una función se declara como *virtual* en la clase base para que pueda ser
sobreeescrita en las clases derivadas.
*/
#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    virtual void actividad() {
        cout << "Persona genérica hace algo." << endl;
    }
};

class Estudiante : public Persona {
public:
    void actividad() override {
        cout << "El estudiante está estudiando." << endl;
    }
};

int main() {
    Persona *p1 = new Estudiante();
    p1->actividad(); // Llama al método de la clase Estudiante

    delete p1;
    return 0;
}
