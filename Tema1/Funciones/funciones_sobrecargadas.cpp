#include <iostream>

using namespace std;

int sumar(int a, int b) {
    return a + b;
}

double sumar(double a, double b) {
    return a + b;
}

int main() {
    cout << sumar(4, 5) << endl;
    cout << sumar(5.5, 6.5) << endl;
    return 0;
}