#include <iostream>

int main() {
    int num;
    std::cout << "Introduce un número" << std::endl;
    std::cin >> num; // Permite al usuario introducir un número
    while (num <= 100) { // Bucle que se ejecutará mientras que el número sea menor que 100
        std::cout << num << std::endl;
        num++; // Incrementa en uno el número declarado fuera del bucle
    }
    return 0;
}