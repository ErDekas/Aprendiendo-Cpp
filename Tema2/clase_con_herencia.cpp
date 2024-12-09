/*
Herencia:
La herencia permite que una clase (hija)
herede atributos y métodos de tora clase (padre).
*/
/*
class ClaseHija : public ClasePadre {
    // Código adicional de la clase hija
};
*/
#include <iostream>
#include <string>

using namespace std;

class Persona {
public: 
    string nombre;

    void presentarse() {
        cout << "Hola, soy " << nombre << "." << endl; 
    }
};

class Estudiante : public Persona {
public:
    string carrera;

    void estudiar() {
        cout << nombre << " está estudiado " << carrera << "." << endl;
    }
};

int main() {
    Estudiante e1;
    e1.nombre = "Pablo";
    e1.carrera = "Desarrollo Web";
    e1.presentarse();
    e1.estudiar();

    return 0;
}