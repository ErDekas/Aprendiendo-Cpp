#include <iostream>
#include <string>
using namespace std;

int main() {
    string palabra;
    cout << "Introduce una palabra para verla invertida" << endl;
    cin >> palabra;
    string palabra_invertida;
    for(int i = palabra.length() - 1; i>=0; i--){
        palabra_invertida.push_back(palabra[i]);
    }
    cout << palabra_invertida << endl;
    return 0;
}