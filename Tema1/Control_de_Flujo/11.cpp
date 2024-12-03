#include <iostream>

using namespace std;
int main() {
    cout << "Introduce un número" << endl;
    int num;
    cin >> num;
    int num_copia = num;
    while(num_copia==num){
        for(int i = 0; i <= 10; i++) {
            cout << num << " x " << i << " = " << num*i << "\n"<< endl;
        }
        num++;
    }
}