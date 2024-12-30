#include <iostream>
#include <string>

using namespace std;

class Empleado {
protected:
    string nombre;
    double salario;

public:
    Empleado(const string& nombre, double salario) : nombre(nombre), salario(salario) {}
    virtual ~Empleado() {}

    virtual double calcularBonus() const = 0; // Método virtual puro

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << ", Salario: " << salario << ", Bonus: " << calcularBonus() << endl;
    }
};

class EmpleadoTiempoCompleto : public Empleado {
public:
    EmpleadoTiempoCompleto(const string& nombre, double salario) : Empleado(nombre, salario) {}

    double calcularBonus() const override {
        return salario * 0.10; // 10% del salario como bonus
    }
};

class EmpleadoMedioTiempo : public Empleado {
public:
    EmpleadoMedioTiempo(const string& nombre, double salario) : Empleado(nombre, salario) {}

    double calcularBonus() const override {
        return salario * 0.05; // 5% del salario como bonus
    }
};

int main() {
    Empleado* empleados[] = {
        new EmpleadoTiempoCompleto("Juan", 50000),
        new EmpleadoMedioTiempo("Ana", 25000)
    };

    for (Empleado* empleado : empleados) {
        empleado->mostrarInformacion();
        delete empleado;
    }

    return 0;
}