#include <iostream>
int main() {
    int num;
    std::cout << "Introduce un número" << std::endl;
    std::cin >> num;

    if (num % 2 == 0){
        std::cout << "El número es par" << std::endl;
    } else {
        std::cout << "El número es impar" << std::endl;
    }
}