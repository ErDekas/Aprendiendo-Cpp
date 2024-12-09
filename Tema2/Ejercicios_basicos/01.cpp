#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    Persona p1;
    p1.nombre =  "Pablo";;
    p1.edad = 19;
    p1.presentarse();
    Persona p2;
    p2.nombre = "Cristina";
    p2.edad = 20;
    p2.presentarse();
    Persona p3;
    cin >> p3.nombre;
    cin >> p3.edad;
    p3.presentarse(); 
}