#include <iostream>

int main() {
    int celsius = 0;
    int temperatura;
    std::cout << "Introduce la temperatura en Celsius " << std::endl;
    std::cin >> temperatura;
    celsius = temperatura;
    int fahrenheit = (celsius * 1.8) + 32;
    std::cout << "La temperatura en Fahrenheit es " << fahrenheit << std::endl;
}