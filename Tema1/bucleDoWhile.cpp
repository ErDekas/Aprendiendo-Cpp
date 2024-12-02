#include <iostream>

int main() {
    int num;
    std::cout << "Introduce un número" << std::endl;
    std::cin >> num;
    do { // Bucle que ejecuta una acción y después la comprueba
        std::cout << num << std::endl;
        num++; // Incrementa en uno el número declarado fuera del bucle
    }while(num<100); // Condición que comprueba que el número sea menor que 100, si es verdad, vuelve al do
    return 0;
}