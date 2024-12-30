#include <iostream>
#include <vector>

class Polinomio {
private:
    std::vector<int> coeficientes;

public:
    Polinomio(const std::vector<int>& coef) : coeficientes(coef) {}

    Polinomio operator+(const Polinomio& otro) const {
        std::vector<int> resultado;
        size_t maxSize = std::max(coeficientes.size(), otro.coeficientes.size());
        resultado.resize(maxSize, 0);

        for (size_t i = 0; i < coeficientes.size(); ++i) {
            resultado[i] += coeficientes[i];
        }

        for (size_t i = 0; i < otro.coeficientes.size(); ++i) {
            resultado[i] += otro.coeficientes[i];
        }

        return Polinomio(resultado);
    }

    void imprimir() const {
        for (size_t i = 0; i < coeficientes.size(); ++i) {
            if (i > 0 && coeficientes[i] >= 0) {
                std::cout << "+ ";
            }
            std::cout << coeficientes[i];
            if (i > 0) {
                std::cout << "x^" << i;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> coef1 = {1, 2, 3}; // Representa 1 + 2x + 3x^2
    std::vector<int> coef2 = {3, 4, 5}; // Representa 3 + 4x + 5x^2

    Polinomio p1(coef1);
    Polinomio p2(coef2);

    Polinomio suma = p1 + p2;

    std::cout << "Polinomio 1: ";
    p1.imprimir();

    std::cout << "Polinomio 2: ";
    p2.imprimir();

    std::cout << "Suma: ";
    suma.imprimir();

    return 0;
}