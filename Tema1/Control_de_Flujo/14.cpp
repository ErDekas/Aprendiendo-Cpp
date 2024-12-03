#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    cout << "Introduce dos números" << endl;
    cin >> num1 >> num2;
    cout << "Los números pares encontrados entre ellos dos son: " << endl;
    while(num1 != num2) {
        if(num1 % 2 == 0) {
            cout << num1 << endl;
            num1--;
        } else {
            num1--;
        }
    }
}