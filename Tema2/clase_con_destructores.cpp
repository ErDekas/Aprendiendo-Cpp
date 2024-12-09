#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    Persona(string _nombre) {
        nombre = _nombre;
    }

    // Destructor
    /*
    Un destructor es un método especial que se llama de forma automática
    cuando un objeto sale de su ámbito. Se usa para liberar recursos.
    */
    ~Persona() {
        cout << "Adiós, " << nombre << "." << endl;
    }
};

int main() {
    Persona p1("Pablo"); // Constructor
    // Destructor se llama automáticamente al final del ámbito
    return 0;
}