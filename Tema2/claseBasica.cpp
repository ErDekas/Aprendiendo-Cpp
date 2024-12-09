#include <iostream>
#include <string>

using namespace std;

// Definición de una clase
class Persona {
public: // Acceso público
    string nombre;
    int edad;

    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años. " << endl;
    }
};

int main() {
    // Creación de un objeto
    Persona p1;
    p1.nombre = "Pablo";
    p1.edad = 18;
    p1.presentarse(); // Llamada a un método

    return 0;
}