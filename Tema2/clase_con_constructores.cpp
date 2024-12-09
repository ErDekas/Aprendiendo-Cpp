#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    // Constructor
    Persona(string _nombre, int _edad){
        nombre = _nombre;
        edad = _edad;
    }

    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    Persona p1("Pablo", 18); // Llama automáticamente al constructor
    p1.presentarse();

    return 0;
}