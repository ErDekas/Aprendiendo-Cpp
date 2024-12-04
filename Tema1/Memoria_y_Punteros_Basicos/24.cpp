#include <iostream>

using namespace std;

int main(){
    int n;

    cout << "¿Cúantos números quieres introducir?" << endl;
    cin >> n;

    if(n<=0){
        cout << "El tamaño del array debe ser superior a 0" << endl;
        return 1;
    }

    int *arr = new int[n];

    cout << "Introduce " << n << " números" << endl;
    for(int i = 0; i < n; i++){
        cout << "Número: " << i + 1 << endl;
        cin >> *(arr + i);
    }

    int* max = arr;
    for(int i = 1; i < n; ++i){
        if(*(arr +i) > *max){
            max = (arr + i);
        }
    }

    cout << "El mayor número es: " << *max << endl;

    delete[] arr;
    
    return 0;
}