#include <iostream>
#include <cmath>

int main() {
    double nota1, nota2, nota3;
    std::cout << "Introduce tus notas: " << std::endl;
    std::cin >> nota1 >> nota2 >> nota3;
    double media = (nota1 + nota2 + nota3) / 3;
    double media_redondeada = std::round(media);
    std::cout << "La nota media de entre las tres notas es: " << media_redondeada << std::endl;
}