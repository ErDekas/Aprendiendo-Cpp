#include <iostream>
#include <string>

using namespace std;

class Rectangulo {
public:
    int largo;
    int ancho;

    int area(){
        return largo * ancho;
    }
    int perimetro(){
        return 2*(largo*ancho);
    }
};

int main() {
    Rectangulo r1;
    r1.largo = 5;
    r1.ancho = 2;
    cout << r1.area() << "\n" << endl;
    cout << r1.perimetro() << endl;
}