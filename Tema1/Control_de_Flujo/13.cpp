#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Introduce un número entero positivo" << endl;
    cin >> n;
    while(n<0){
        cout << "Introduce un número válido" << endl;
        cin >> n;
    }
    int resultado = 1;
    do {
        resultado *= n;
        n--;
    } while(n > 0);
    cout << resultado << endl;
    return 0;
}