#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

// Clase base Cuenta
class Cuenta {
protected:
    string titular;
    string contrasena;
    double saldo;

public:
    Cuenta(const string& titular, const string& contrasena, double saldoInicial) 
        : titular(titular), contrasena(contrasena), saldo(saldoInicial) {}

    virtual ~Cuenta() {}

    virtual void depositar(double monto) {
        saldo += monto;
        cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
    }

    virtual void retirar(double monto) {
        if (monto > saldo) {
            cout << "Saldo insuficiente." << endl;
        } else {
            saldo -= monto;
            cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        }
    }

    virtual void mostrarSaldo() const {
        cout << "Titular: " << titular << ", Saldo: " << saldo << endl;
    }

    virtual string tipoCuenta() const = 0; // Método virtual puro

    string getTitular() const {
        return titular;
    }

    string getContrasena() const {
        return contrasena;
    }
};

// Clase derivada CuentaPersonal
class CuentaPersonal : public Cuenta {
public:
    CuentaPersonal(const string& titular, const string& contrasena, double saldoInicial) 
        : Cuenta(titular, contrasena, saldoInicial) {}

    string tipoCuenta() const override {
        return "Cuenta Personal";
    }
};

// Clase derivada CuentaEmpresarial
class CuentaEmpresarial : public Cuenta {
public:
    CuentaEmpresarial(const string& titular, const string& contrasena, double saldoInicial) 
        : Cuenta(titular, contrasena, saldoInicial) {}

    string tipoCuenta() const override {
        return "Cuenta Empresarial";
    }
};

// Funciones auxiliares
void mostrarMenu() {
    cout << "\n--- Simulador Bancario ---\n";
    cout << "1. Crear cuenta\n";
    cout << "2. Depositar\n";
    cout << "3. Retirar\n";
    cout << "4. Consultar saldo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

shared_ptr<Cuenta> buscarCuentaPorTitularYContrasena(const vector<shared_ptr<Cuenta>>& cuentas, const string& titular, const string& contrasena) {
    for (const auto& cuenta : cuentas) {
        if (cuenta->getTitular() == titular && cuenta->getContrasena() == contrasena) {
            return cuenta;
        }
    }
    return nullptr;
}

void crearCuenta(vector<shared_ptr<Cuenta>>& cuentas) {
    string nombre, contrasena;
    double saldoInicial;
    int tipo;

    cout << "Ingrese el nombre del titular: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la contraseña: ";
    getline(cin, contrasena);

    cout << "Ingrese el saldo inicial: ";
    cin >> saldoInicial;
    cout << "Seleccione el tipo de cuenta (1. Personal, 2. Empresarial): ";
    cin >> tipo;

    if (tipo == 1) {
        cuentas.push_back(make_shared<CuentaPersonal>(nombre, contrasena, saldoInicial));
        cout << "Cuenta personal creada exitosamente." << endl;
    } else if (tipo == 2) {
        cuentas.push_back(make_shared<CuentaEmpresarial>(nombre, contrasena, saldoInicial));
        cout << "Cuenta empresarial creada exitosamente." << endl;
    } else {
        cout << "Tipo de cuenta inválido." << endl;
    }
}

void realizarOperacion(vector<shared_ptr<Cuenta>>& cuentas, int opcion) {
    if (cuentas.empty()) {
        cout << "No hay cuentas creadas." << endl;
        return;
    }

    string titular, contrasena;
    double monto;

    cout << "Ingrese el nombre del titular de la cuenta: ";
    cin.ignore();
    getline(cin, titular);

    cout << "Ingrese la contraseña: ";
    getline(cin, contrasena);

    auto cuenta = buscarCuentaPorTitularYContrasena(cuentas, titular, contrasena);
    if (!cuenta) {
        cout << "Cuenta no encontrada o contraseña incorrecta." << endl;
        return;
    }

    switch (opcion) {
        case 2: // Depositar
            cout << "Ingrese el monto a depositar: ";
            cin >> monto;
            cuenta->depositar(monto);
            break;
        case 3: // Retirar
            cout << "Ingrese el monto a retirar: ";
            cin >> monto;
            cuenta->retirar(monto);
            break;
        case 4: // Consultar saldo
            cuenta->mostrarSaldo();
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
    }
}

int main() {
    vector<shared_ptr<Cuenta>> cuentas;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearCuenta(cuentas);
                break;
            case 2:
            case 3:
            case 4:
                realizarOperacion(cuentas, opcion);
                break;
            case 5:
                cout << "Saliendo del sistema bancario." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 5);

    return 0;
}