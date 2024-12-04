#include <iostream>

using namespace std;

int main(){
    int n;

    cout << "¿Cúantos número quieres introducir?" << endl;
    cin >> n;
    
    if(n<=0){
        cout << "El tamaño del array debe ser superior a 0" << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "Introducir: " << n << " números" << endl;
    for(int i = 0; i < n; ++i){
        cout << "Número: " << i + 1 << endl;
        cin >> *(arr + i);
    }

    int* start = arr;
    int* end = arr + n - 1;
    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        *start++;
        *end--;
    }

    cout << "Array  invertido: " << endl;
    for(int i = 0; i < n; ++i){
        cout << *(arr + i) << " " << endl;
    }
    delete[] arr;

    return 0;
}