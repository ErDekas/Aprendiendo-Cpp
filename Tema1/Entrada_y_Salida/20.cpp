#include <iostream>
#include <string>
using namespace std;

int main() {
    string palabra;
    string palabra_invertida;
    cout << "Introduce una palabra" << endl;
    cin >> palabra;

    for(int i = palabra.length() - 1; i>=0; i--){
        palabra_invertida += palabra[i];
    }

    if(palabra == palabra_invertida) {
        cout << "La palabra es palíndroma" << endl;
    } else {
        cout << "La palabra no es un palíndromo" << endl;
    }
}