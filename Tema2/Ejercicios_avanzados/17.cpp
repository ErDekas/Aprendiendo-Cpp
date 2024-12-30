#include <iostream>

using namespace std;

class Vehiculo {
public:
    virtual double consumoCombustible(double distancia) = 0; // Método virtual puro
    virtual ~Vehiculo() {} // Destructor virtual
};

class Coche : public Vehiculo {
public:
    double consumoCombustible(double distancia) override {
        // Supongamos que el coche consume 8 litros por cada 100 km
        return (distancia / 100) * 8;
    }
};

class Moto : public Vehiculo {
public:
    double consumoCombustible(double distancia) override {
        // Supongamos que la moto consume 5 litros por cada 100 km
        return (distancia / 100) * 5;
    }
};

int main() {
    Vehiculo* vehiculo1 = new Coche();
    Vehiculo* vehiculo2 = new Moto();

    double distancia = 150; // Distancia en kilómetros

    cout << "Consumo de combustible del coche para " << distancia << " km: " 
              << vehiculo1->consumoCombustible(distancia) << " litros" << endl;
    cout << "Consumo de combustible de la moto para " << distancia << " km: " 
              << vehiculo2->consumoCombustible(distancia) << " litros" << endl;

    delete vehiculo1;
    delete vehiculo2;

    return 0;
}