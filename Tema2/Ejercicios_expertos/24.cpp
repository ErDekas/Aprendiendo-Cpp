#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

class Estudiante {
private:
    std::string nombre;
    std::vector<float> calificaciones;

public:
    Estudiante(std::string nombre) : nombre(nombre) {}

    void agregarCalificacion(float calificacion) {
        calificaciones.push_back(calificacion);
    }

    float obtenerPromedio() const {
        if (calificaciones.empty()) return 0.0f;
        float suma = 0;
        for (float calif : calificaciones) {
            suma += calif;
        }
        return suma / calificaciones.size();
    }

    std::string getNombre() const { return nombre; }
    const std::vector<float>& obtenerCalificaciones() const { return calificaciones; }
};

class GestorEstudiantes {
private:
    std::vector<Estudiante> estudiantes;

public:
    void agregarEstudiante(const Estudiante& estudiante) {
        estudiantes.push_back(estudiante);
    }

    float promedioGeneral() const {
        if (estudiantes.empty()) return 0.0f;
        float sumaPromedios = 0;
        for (const Estudiante& est : estudiantes) {
            sumaPromedios += est.obtenerPromedio();
        }
        return sumaPromedios / estudiantes.size();
    }

    const std::vector<Estudiante>& obtenerEstudiantes() const {
        return estudiantes;
    }

    Estudiante obtenerMejorEstudiante() const {
        if (estudiantes.empty()) {
            return Estudiante("No hay estudiantes");
        }
        
        auto mejorEstudiante = std::max_element(
            estudiantes.begin(), 
            estudiantes.end(),
            [](const Estudiante& a, const Estudiante& b) {
                return a.obtenerPromedio() < b.obtenerPromedio();
            }
        );
        
        return *mejorEstudiante;
    }
};

#include <iostream>
#include <iomanip> // Para std::fixed y std::setprecision
// ...existing code...

int main() {
    GestorEstudiantes gestor;

    // Ejemplo de uso
    Estudiante est1("Juan");
    est1.agregarCalificacion(8.5);
    est1.agregarCalificacion(9.0);
    est1.agregarCalificacion(7.5);

    Estudiante est2("Maria");
    est2.agregarCalificacion(9.5);
    est2.agregarCalificacion(9.0);
    est2.agregarCalificacion(9.5);

    gestor.agregarEstudiante(est1);
    gestor.agregarEstudiante(est2);

    // Configurar la precisión para truncar a un decimal
    std::cout << std::fixed << std::setprecision(1);

    // Imprimir la tabla de estudiantes
    std::cout << "Nombre\tNota 1\tNota 2\tNota 3\tPromedio\n";
    for (const auto& estudiante : gestor.obtenerEstudiantes()) {
        std::cout << estudiante.getNombre() << "\t";
        const auto& calificaciones = estudiante.obtenerCalificaciones();
        for (const auto& nota : calificaciones) {
            std::cout << nota << "\t";
        }
        std::cout << estudiante.obtenerPromedio() << "\n";
    }

    // Imprimir el promedio general
    std::cout << "Promedio general: " << gestor.promedioGeneral() << std::endl;
    std::cout << "Mejor estudiante: " << gestor.obtenerMejorEstudiante().getNombre() 
              << " con promedio: " << gestor.obtenerMejorEstudiante().obtenerPromedio() << std::endl;

    return 0;
}