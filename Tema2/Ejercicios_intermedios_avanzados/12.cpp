#include <iostream>
#include <string>

using namespace std;

class Figura {
public:
    double base;
    double altura;

    double calcularArea() {
        return base*altura;
    }
};

class Circulo : public Figura {
private:
    double radio;
    double const pi = 3.14;
public:
    Circulo(double _radio) {
        radio = _radio;
    }
    double calcularArea() {
        return pi * (radio*radio);
    }
};

class Rectangulo : public Figura {
public:
    Rectangulo(double _base, double _altura) {
        base = _base;
        altura = _altura;
    }
    double calcularArea() {
        return base * altura;
    };
};

class Triangulo : public Figura {
public:
    Triangulo(double _base, double _altura) {
        base = _base;
        altura = _altura;
    }
    double calcularArea() {
        return (base * altura) / 2;
    }
};

int main() {
    Circulo c1(10);
    cout << c1.calcularArea() << endl;
    Rectangulo r1(2,5);
    cout << r1.calcularArea() << endl;
    Triangulo t1(2,5);
    cout << t1.calcularArea() << endl;
}