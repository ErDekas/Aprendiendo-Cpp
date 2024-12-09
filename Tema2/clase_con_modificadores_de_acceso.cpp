/*
Modificadores de Acceso
- public: Accesible desde cualquier parte del programa.
- private: Solo acccesible dentro de la misma clase.
- protected: Accesible desde la clase y sus deriada.
*/

#include <iostream>
#include <string>

using namespace std;
class Persona {
    private:
        string nombre; 

    public:
        void setNombre(string _nombre) {
            nombre = _nombre; // Método público para modificar un atributo privado
        
        }
        string getNombre() {
            return nombre; // Método público para acceder al atributo
        }
};

int main() {
    Persona p1;
    p1.setNombre("Pablo");
    cout << "Nombre: " << p1.getNombre() << endl;

    return 0;
}