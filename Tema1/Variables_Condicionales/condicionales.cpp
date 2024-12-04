#include <iostream>

int main() {
    int edad = 18;

    if (edad > 18) { // Condicional que compara tu edad para saber si es mayor de 18
        std::cout << "Eres mayor de edad, puedes pasar" << std::endl;
    } else if (edad < 18) { // Condicional que compara tu edad para saber si es menor de 18, se efectúa después de comprobar la primera condición
        std::cout << "Eres menor de edad, no puedes pasar" << std::endl;
    } else { // Codicional que se ejecuta si ninguna de las anteriores se cumple
        std::cout << "No puedes pasar sin verificar tu edad" << std::endl;
    }
}