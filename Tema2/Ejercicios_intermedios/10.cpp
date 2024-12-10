#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    int cantidad;

    Producto(string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}
};

class Inventario {
private:
    vector<Producto> productos;

public:
    // Agregar un producto
    void agregarProducto(const string& nombre, int cantidad) {
        for (auto& producto : productos) {
            if (producto.nombre == nombre) {
                producto.cantidad += cantidad;
                cout << "Cantidad actualizada para: " << nombre << endl;
                return;
            }
        }
        productos.emplace_back(nombre, cantidad);
        cout << "Producto agregado: " << nombre << endl;
    }

    // Eliminar un producto
    void eliminarProducto(const string& nombre) {
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            if (it->nombre == nombre) {
                productos.erase(it);
                cout << "Producto eliminado: " << nombre << endl;
                return;
            }
        }
        cout << "Producto no encontrado: " << nombre << endl;
    }

    // Listar productos
    void listarProductos() const {
        if (productos.empty()) {
            cout << "El inventario está vacío." << endl;
            return;
        }

        cout << "Productos en el inventario:" << endl;
        for (const auto& producto : productos) {
            cout << "- " << producto.nombre << " (Cantidad: " << producto.cantidad << ")" << endl;
        }
    }
};

int main() {
    Inventario inventario;

    int opcion;
    string nombre;
    int cantidad;

    do {
        cout << "\nSistema de Inventario" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Listar productos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del producto: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, nombre);
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;
            inventario.agregarProducto(nombre, cantidad);
            break;
        case 2:
            cout << "Ingrese el nombre del producto a eliminar: ";
            cin.ignore();
            getline(cin, nombre);
            inventario.eliminarProducto(nombre);
            break;
        case 3:
            inventario.listarProductos();
            break;
        case 4:
            cout << "Saliendo del sistema." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);

    return 0;
}
