#include <iostream>

int main() {
    int num1, num2;
    char operacion;

    std::cout << "Introduce tu primer número" << std::endl;
    std::cin >> num1;
    std::cout << "Introduce tu segundo número" << std::endl;
    std::cin >> num2;
    do {
    std::cout << "Introduce tu operación: (+, -, *, /), para terminar el programa pulse c" << std::endl;
    std::cin >> operacion;

    if(operacion == '+') {
        std::cout << num1 + num2 << std::endl;
    } else if(operacion == '-') {
        std::cout << num1 - num2 << std::endl;
    }else if(operacion == '*') {
        std::cout << num1 * num2 << std::endl;
    }else if(operacion == '/') {
        std::cout << num1 / num2 << std::endl;
    } else {
        std::cout << "Operación no válida" << std::endl;
    }
    } while (operacion != 'c');
}