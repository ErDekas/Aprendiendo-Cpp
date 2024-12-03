#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int numeroSecreto = rand() % 101 + 1;
    int n;
    cout << "Adivine el número secreto entre 1 y 100" << endl;
    while(n!=numeroSecreto){
        cin >> n;
        if(n>numeroSecreto){
            cout << "Muy alto" << endl;
        } else if(n<numeroSecreto){
            cout << "Muy bajo" << endl;
        } else {
            cout << "Felicidades has ganado" << endl;
        }
    }
}