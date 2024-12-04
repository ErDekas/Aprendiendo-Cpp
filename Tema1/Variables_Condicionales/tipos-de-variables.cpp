#include <iostream>

int main() {
    // Tipos de variable
    int entero = 5; // Entero
    float decimal = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706795; // Flotante
    char caracter = 'a'; // Caracter único
    bool verdadero = true; // Booleano
    double decimal_exacto = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706795; // Double
    std::string cadena = "Hola Mundo!"; // Cadena

    std::cout << "Tipos de variables: " <<
        "\nEntero: " << entero <<
        "\nFlotante: " << decimal <<
        "\nCaracter: " << caracter <<
        "\nBooleano: " << verdadero <<
        "\nDecimal: " << decimal_exacto <<
        "\nCadena: " << cadena << std::endl;
}