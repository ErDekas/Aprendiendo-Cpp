#include <iostream>
#include <string>

using namespace std;

class Producto {
public:
    string nombre;
    double precio;
    int cantidad;

    Producto(string _nombre, double _precio, int _cantidad) {
        nombre = _nombre;
        precio = _precio;
        cantidad = _cantidad;
    }

    double costoTotal() {
        return precio * cantidad;
    }
};

int main() {
    Producto p1("Leche", 5.5, 5);
    cout << p1.costoTotal() << endl;
}