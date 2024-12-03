#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
int main() {
    int numero_random = rand() % 11;
    int exponente_random = rand() % 11;
    int resultado = pow(numero_random, exponente_random);
    cout << "El resultado de elevar " << numero_random << " a " << exponente_random << " es: " << resultado << endl;
}