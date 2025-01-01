#include <iostream>
#include <vector>
#include <string>

class Habitacion {
private:
    int numero;
    bool ocupada;
    double precioPorNoche;
    std::string tipo; // "Individual", "Doble", "Suite"

public:
    Habitacion(int num, std::string t, double precio) : 
        numero(num), tipo(t), precioPorNoche(precio), ocupada(false) {}

    bool estaOcupada() const { return ocupada; }
    void setOcupada(bool estado) { ocupada = estado; }
    double getPrecio() const { return precioPorNoche; }
    int getNumero() const { return numero; }
    std::string getTipo() const { return tipo; }
};

class Reserva {
private:
    int numeroReserva;
    Habitacion* habitacion;
    std::string nombreCliente;
    int dias;
    static int contadorReservas;

public:
    Reserva(Habitacion* hab, std::string nombre, int numDias) : 
        habitacion(hab), nombreCliente(nombre), dias(numDias) {
        numeroReserva = ++contadorReservas;
        habitacion->setOcupada(true);
    }

    double calcularCosto() const {
        return habitacion->getPrecio() * dias;
    }

    void mostrarDetalles() const {
        std::cout << "Reserva #" << numeroReserva << "\n"
                  << "Cliente: " << nombreCliente << "\n"
                  << "Habitación: " << habitacion->getNumero() << " (" << habitacion->getTipo() << ")\n"
                  << "Días: " << dias << "\n"
                  << "Costo total: $" << calcularCosto() << "\n";
    }
};

class Hotel {
private:
    std::vector<Habitacion> habitaciones;
    std::vector<Reserva> reservas;

public:
    Hotel() {
        // Inicializar algunas habitaciones
        habitaciones.push_back(Habitacion(101, "Individual", 50.0));
        habitaciones.push_back(Habitacion(102, "Doble", 80.0));
        habitaciones.push_back(Habitacion(103, "Suite", 150.0));
    }

    void mostrarHabitacionesDisponibles() const {
        std::cout << "\nHabitaciones disponibles:\n";
        for (const auto& hab : habitaciones) {
            if (!hab.estaOcupada()) {
                std::cout << "Habitación " << hab.getNumero() 
                         << " - Tipo: " << hab.getTipo()
                         << " - Precio: $" << hab.getPrecio() << "/noche\n";
            }
        }
    }

    bool realizarReserva(int numHabitacion, std::string nombre, int dias) {
        for (auto& hab : habitaciones) {
            if (hab.getNumero() == numHabitacion && !hab.estaOcupada()) {
                reservas.push_back(Reserva(&hab, nombre, dias));
                std::cout << "\nReserva realizada con éxito!\n";
                reservas.back().mostrarDetalles();
                return true;
            }
        }
        std::cout << "No se pudo realizar la reserva.\n";
        return false;
    }
};

int Reserva::contadorReservas = 0;

int main() {
    Hotel hotel;
    int opcion;

    do {
        std::cout << "\n=== Sistema de Reservas de Hotel ===\n"
                  << "1. Ver habitaciones disponibles\n"
                  << "2. Realizar reserva\n"
                  << "3. Salir\n"
                  << "Elija una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                hotel.mostrarHabitacionesDisponibles();
                break;
            case 2: {
                int numHab, dias;
                std::string nombre;
                std::cout << "Número de habitación: ";
                std::cin >> numHab;
                std::cout << "Nombre del cliente: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Número de días: ";
                std::cin >> dias;
                hotel.realizarReserva(numHab, nombre, dias);
                break;
            }
            case 3:
                std::cout << "¡Gracias por usar nuestro sistema!\n";
                break;
            default:
                std::cout << "Opción inválida\n";
        }
    } while (opcion != 3);

    return 0;
}