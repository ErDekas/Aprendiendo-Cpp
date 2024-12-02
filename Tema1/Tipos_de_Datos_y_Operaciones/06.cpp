#include <iostream>

int main() {
    const double pi = 3.1416; // Constante con valor 3.1416
    double radio;
    std::cout << "Introduce el radio del circulo" << std::endl;
    std::cin >> radio;
    double area = radio * radio * pi; // Calcula el área del círculo
    std::cout << "El área del círculo es: " << area << std::endl;
    return 0;
}