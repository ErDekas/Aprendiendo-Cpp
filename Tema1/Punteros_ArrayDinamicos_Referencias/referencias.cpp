#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int y = 10;

    int *p = &x; // Puntero que apunta a x
    p = &y; // Ahora apunta a y

    int &ref = x; // Referencia a x
    // ref = &y; // ERROR: Una referencia no puede cambiar su variable referenciada
}