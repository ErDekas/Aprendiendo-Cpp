#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    Persona p1("Pablo", 19);
    p1.presentarse();
    Persona p2("Cristina", 20);
    p2.presentarse();
    string nombre;
    int edad;
    cin >> nombre >> edad;
    Persona p3(nombre, edad);
    p3.presentarse(); 
}