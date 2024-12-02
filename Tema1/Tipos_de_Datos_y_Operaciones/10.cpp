#include <iostream>

int main() {
    double tasa_cambio = 1.05; // Tasa cambio de euro a dólar
    double euros;
    std::cout << "Introduce una cantidad de euros" << std::endl;
    std::cin >> euros;
    double dolares = euros * tasa_cambio;
    std::cout << euros << " euros son " << dolares << " dolares" << std::endl;
    return 0;
}