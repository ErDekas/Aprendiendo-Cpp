#include <iostream>

using namespace std;

int main() {
    const int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    int *ptr = arr;

    int sum = 0;

    for(int i=0; i < size; i++){
        sum+= *(ptr + i);
    }

    cout << "La suma de los elementos del array es: " << sum << endl;
}