#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Tarea {
public:
    Tarea(const std::string& titulo) : titulo(titulo), estado(false) {}

    void marcarCompletada() {
        estado = true;
    }

    std::string obtenerTitulo() const {
        return titulo;
    }

    bool estaCompletada() const {
        return estado;
    }

private:
    std::string titulo;
    bool estado;
};

class GestorTareas {
public:
    void agregarTarea(const std::string& titulo) {
        tareas.push_back(Tarea(titulo));
    }

    void marcarTareaCompletada(const std::string& titulo) {
        auto it = std::find_if(tareas.begin(), tareas.end(), [&titulo](const Tarea& tarea) {
            return tarea.obtenerTitulo() == titulo;
        });
        if (it != tareas.end()) {
            it->marcarCompletada();
        } else {
            std::cout << "Tarea no encontrada.\n";
        }
    }

    void mostrarTareas() const {
        for (const auto& tarea : tareas) {
            std::cout << tarea.obtenerTitulo() << " - " << (tarea.estaCompletada() ? "Completada" : "Pendiente") << '\n';
        }
    }

private:
    std::vector<Tarea> tareas;
};

int main() {
    GestorTareas gestor;
    std::string comando;
    std::string titulo;

    while (true) {
        std::cout << "Ingrese un comando (Agregar(1), Completar(2), Mostrar(3), Salir(0)): ";
        std::cin >> comando;

        if (comando == "salir" || comando == "SALIR" || comando == "Salir" || comando == "0") {
            break;
        } else if (comando == "agregar" || comando == "AGREGAR" || comando == "Agregar" || comando == "1") {
            std::cout << "Ingrese el título de la tarea: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            gestor.agregarTarea(titulo);
        } else if (comando == "completar" || comando == "COMPLETAR" || comando == "Completar" || comando == "2") {
            std::cout << "Ingrese el título de la tarea a completar: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            gestor.marcarTareaCompletada(titulo);
        } else if (comando == "mostrar" || comando == "MOSTRAR" || comando == "Mostrar" || comando == "3") {
            gestor.mostrarTareas();
        } else {
            std::cout << "Comando no reconocido.\n";
        }
    }

    return 0;
}