#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "Introduce tus tres números" << std::endl;
    std::cin >> num1 >> num2 >> num3;
    if(num1 > num2 && num1 > num3) {
        if(num2>num3){
        std::cout << num1 << " es el mayor y " << num3 << " es el menor" << std::endl;
        } else {
        std::cout << num1 << " es el mayor y " << num2 << " es el menor" << std::endl;
        }
    } else if(num2 > num1 && num2 > num3) {
        if(num1>num3){
        std::cout << num2 << " es el mayor y " << num3 << " es el menor" << std::endl;
        } else {
        std::cout << num2 << " es el mayor y " << num1 << " es el menor" << std::endl;
        }
    } else if(num3 > num1 && num3 > num2) {
        if(num1>num2){
        std::cout << num3 << " es el mayor y " << num2 << " es el menor" << std::endl;
        } else {
        std::cout << num3 << " es el mayor y " << num1 << " es el menor" << std::endl;
        }
    } else {
        std::cout << "Los tres números son iguales" << std::endl;
    }
}