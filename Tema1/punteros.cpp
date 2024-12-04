#include <iostream>

using namespace std;

int main() {
    /* int *ptr; Un puntero, es una variable que puede almacenar 
                la dirección de un entero */
    int a = 10;
    int *ptr = &a; // El puntero 'ptr' almacena la dirección de 'a'

    /* int *ptr = nullptr; Buen hábito inicializar punteros;

    /* El operador de dirección &: Obtiene la dirección de memoria
    de una varible 
    El operador de desreferencia *: Accede al valor almacenado en la
    dirección a la que apunta el puntero */

    cout << "Valor de x: " << a << endl;
    cout << "Dirección de a: " << &a << endl;
    cout << "Valor de ptr(dirección de x): " << ptr << endl;
    cout << "Valor en la dirección que apunta p: " << *ptr << endl;

    return 0;
}