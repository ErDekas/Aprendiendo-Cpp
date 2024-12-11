#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
public:
    double velocidad;
    double mover(double distancia) {
        return velocidad + distancia;
    }
};

class Coche : public Vehiculo {
public:
    Coche(double _velocidad) {
        velocidad = _velocidad;
    }
    double mover(double distancia) {
        return velocidad * distancia; 
    }
};

class Bicicleta : public Vehiculo {
public:
    Bicicleta(double _velocidad) {
        velocidad = _velocidad;
    }
    double mover(double distancia) {
        return velocidad + distancia;
    }
};

int main() {
    Coche c1(200);
    cout << c1.mover(20) << endl;
    Bicicleta b1(20);
    cout << b1.mover(20) << endl;
}