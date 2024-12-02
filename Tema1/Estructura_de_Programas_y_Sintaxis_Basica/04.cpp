#include <iostream>
int main() {
    int num1, num2;
    std::cout << "Introduce tu primer número" << std::endl;
    std::cin >> num1;
    std::cout << "Introduce tu segundo número" << std::endl;
    std::cin >> num2;
    if (num1 > num2) {
        std::cout << num1 << " es mayor que " << num2 << std::endl;
    } else if(num1 < num2) {
        std::cout << num2 << " es mayor que " << num1 << std::endl;
    } else {
        std::cout << num1 << " y " << num2 << " son iguales" << std::endl;
    }
}