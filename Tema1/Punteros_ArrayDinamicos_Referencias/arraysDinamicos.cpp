#include <iostream>

using namespace std;

int main() {
    int *arr = new int[5]; // Reserva memoria para un array de 5 enteros

    for (int i = 0; i < 5; i++){
        arr[i] = i * 10; // Inicializa el array
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " " << endl; // Imprime 0 10 20 30 40
    }

    delete [] arr; // Libera la memroai del array
}