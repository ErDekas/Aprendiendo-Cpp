#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    double saldo;
    string titular;

public:

    CuentaBancaria(double _saldo, string _titular) {
        saldo = _saldo;
        titular = _titular;
    }
    double depositar(double dinero) {
        return saldo += dinero;
    }

    double retirar(double dinero) {
        return saldo-=dinero;
    }

    double consultar() {
        return saldo;
    }
};

int main() {
    CuentaBancaria cb(3000.0, "Pablo");
    cb.depositar(250.53);
    cb.retirar(1000);
    cout << cb.consultar();
    return 0;
}