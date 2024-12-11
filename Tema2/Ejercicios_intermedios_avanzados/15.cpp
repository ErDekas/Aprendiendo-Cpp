#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;
    int anio;

    Libro(string titulo, string autor, int anio) : titulo(titulo), autor(autor), anio(anio) {}
};

class Biblioteca {
private:
    vector<Libro> libros;

public:
    // Agregar un libro
    void agregarLibro(const string& titulo, const string& autor, int anio) {
        libros.emplace_back(titulo, autor, anio);
        cout << "Libro agregado: " << titulo << endl;
    }

    // Eliminar un libro
    void eliminarLibro(const string& titulo) {
        for (auto it = libros.begin(); it != libros.end(); ++it) {
            if (it->titulo == titulo) {
                libros.erase(it);
                cout << "Libro eliminado: " << titulo << endl;
                return;
            }
        }
        cout << "Libro no encontrado: " << titulo << endl;
    }

    // Buscar un libro
    void buscarLibro(const string& titulo) const {
        for (const auto& libro : libros) {
            if (libro.titulo == titulo) {
                cout << "Libro encontrado: " << endl;
                cout << "Titulo: " << libro.titulo << endl;
                cout << "Autor: " << libro.autor << endl;
                cout << "Año: " << libro.anio << endl;
                return;
            }
        }
        cout << "Libro no encontrado: " << titulo << endl;
    }

    // Listar todos los libros
    void listarLibros() const {
        if (libros.empty()) {
            cout << "La biblioteca está vacía." << endl;
            return;
        }

        cout << "Libros en la biblioteca:" << endl;
        for (const auto& libro : libros) {
            cout << "- " << libro.titulo << " de " << libro.autor << " (" << libro.anio << ")" << endl;
        }
    }
};

int main() {
    Biblioteca biblioteca;

    int opcion;
    string titulo, autor;
    int anio;

    do {
        cout << "\nSistema de Biblioteca" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Eliminar libro" << endl;
        cout << "3. Buscar libro" << endl;
        cout << "4. Listar libros" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el título del libro: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);
            cout << "Ingrese el año del libro: ";
            cin >> anio;
            biblioteca.agregarLibro(titulo, autor, anio);
            break;
        case 2:
            cout << "Ingrese el título del libro a eliminar: ";
            cin.ignore();
            getline(cin, titulo);
            biblioteca.eliminarLibro(titulo);
            break;
        case 3:
            cout << "Ingrese el título del libro a buscar: ";
            cin.ignore();
            getline(cin, titulo);
            biblioteca.buscarLibro(titulo);
            break;
        case 4:
            biblioteca.listarLibros();
            break;
        case 5:
            cout << "Saliendo del sistema." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}