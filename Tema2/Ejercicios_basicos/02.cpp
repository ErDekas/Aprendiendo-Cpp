#include <iostream>
#include <string>

using namespace std;

class Coche {
public:
    string marca;
    string modelo;
    int anio;

    int antiguedad(int anioActual) {
        return anioActual - anio;
    }

    void mostrarInfo(int anioActual) {
        cout << "Marca: " << marca << "\n" << endl; 
        cout << "Modelo: " << modelo << "\n" << endl;
        cout << "Año: " << anio << "\n" << endl;
        cout << "Antigüedad: " << antiguedad(anioActual) << " años" << endl;
    }
};

int main() {
    Coche c1;
    c1.marca = "Toyota";
    c1.modelo = "Supra";
    c1.anio = 2005;

    int anioActual = 2024;
    c1.mostrarInfo(anioActual);
}