#include <iostream>
int main() {
    int num1, num2;
    std::cout << "Introduce tu primer número" << std::endl;
    std::cin >> num1;
    int num1_copy = num1;
    std::cout << "Introduce tu segundo número" << std::endl;
    std::cin >> num2;

    num1 = num2;
    num2 = num1_copy;
    std::cout << "El valor de num1 ahora es: " << num1 << " y el de num2 es: " << num2 << std::endl;
}