#include <iostream>
#include <string>

using namespace std;

class Cuenta {
protected:
    string titular;
    double saldo;

public:
    Cuenta(const string & titular, double saldo) : titular(titular), saldo(saldo) {}

    virtual void depositar(double cantidad) {
        saldo += cantidad;
    }

    virtual bool retirar(double cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            return true;
        }
        return false;
    }

    virtual void mostrar() const {
        cout << "Titular: " << titular << ", Saldo: " << saldo << endl;
    }

    virtual ~Cuenta() {}
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorro(const string& titular, double saldo, double tasaInteres)
        : Cuenta(titular, saldo), tasaInteres(tasaInteres) {}

    void aplicarInteres() {
        saldo += saldo * tasaInteres;
    }

    void mostrar() const override {
        cout << "Cuenta de Ahorro - Titular: " << titular << ", Saldo: " << saldo << ", Tasa de Interes: " << tasaInteres << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    CuentaCorriente(const string& titular, double saldo, double limiteDescubierto)
        : Cuenta(titular, saldo), limiteDescubierto(limiteDescubierto) {}

    bool retirar(double cantidad) override {
        if (cantidad <= saldo + limiteDescubierto) {
            saldo -= cantidad;
            return true;
        }
        return false;
    }

    void mostrar() const override {
        cout << "Cuenta Corriente - Titular: " << titular << ", Saldo: " << saldo << ", Limite de Descubierto: " << limiteDescubierto << endl;
    }
};

int main() {
    CuentaAhorro ahorro("Pablo", 1000.0, 0.05);
    CuentaCorriente corriente("Pablo", 500.0, 200.0);

    ahorro.mostrar();
    corriente.mostrar();

    ahorro.depositar(200.0);
    corriente.retirar(600.0);

    ahorro.aplicarInteres();
    ahorro.mostrar();
    corriente.mostrar();

    return 0;
}