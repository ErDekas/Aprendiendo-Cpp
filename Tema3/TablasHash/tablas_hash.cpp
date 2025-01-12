/*
    Archivo: tablas_hash.cpp
    Descripción: Este programa explica qué son las tablas hash y muestra un ejemplo práctico de su uso en C++.
*/

#include <iostream>
#include <unordered_map>
#include <string>

/*
    ¿Qué son las tablas hash?
    --------------------------------------
    Una tabla hash es una estructura de datos que almacena pares clave-valor. 
    Se utiliza para realizar búsquedas rápidas, ya que puede acceder a los valores en un tiempo promedio constante O(1), 
    dependiendo de la calidad de la función hash utilizada.

    ¿Para qué sirven?
    --------------------------------------
    Las tablas hash son útiles en situaciones donde se necesita buscar datos rápidamente.
    Algunos ejemplos de uso incluyen:
    - Implementación de diccionarios o mapas de palabras.
    - Cálculo de frecuencias de elementos en listas.
    - Implementación de caches para optimizar procesos.

    En C++, la biblioteca estándar (STL) proporciona la clase `std::unordered_map` 
    que es una implementación de una tabla hash.
*/

// Ejemplo de uso de una tabla hash en C++
int main() {
    // Crear una tabla hash utilizando std::unordered_map
    std::unordered_map<std::string, int> tablaHash;

    // Insertar pares clave-valor en la tabla hash
    tablaHash["Manzana"] = 50;
    tablaHash["Banana"] = 30;
    tablaHash["Cereza"] = 20;

    // Acceder a los valores utilizando las claves
    std::cout << "Precio de una Manzana: " << tablaHash["Manzana"] << " unidades monetarias.\n";
    std::cout << "Precio de una Banana: " << tablaHash["Banana"] << " unidades monetarias.\n";

    // Verificar si una clave existe
    std::string claveBuscada = "Cereza";
    if (tablaHash.find(claveBuscada) != tablaHash.end()) {
        std::cout << "El precio de la " << claveBuscada << " es: " << tablaHash[claveBuscada] << " unidades monetarias.\n";
    } else {
        std::cout << claveBuscada << " no se encuentra en la tabla hash.\n";
    }

    // Mostrar todos los elementos en la tabla hash
    std::cout << "\nContenido de la tabla hash:\n";
    for (const auto& par : tablaHash) {
        std::cout << par.first << " -> " << par.second << "\n";
    }

    return 0;
}
