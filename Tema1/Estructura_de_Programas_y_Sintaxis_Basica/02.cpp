#include <iostream>

int main() {
    int edad;
    std::cout << "Introduce tu edad " << std::endl;
    std::cin >> edad;
    int edad_en_10_anos;
    edad_en_10_anos = edad + 10;
    std::cout << "En 10 años tendras " << edad_en_10_anos << std::endl;
}