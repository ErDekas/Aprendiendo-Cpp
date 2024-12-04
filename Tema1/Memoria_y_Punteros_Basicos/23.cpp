#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "¿Cuantos números quieres introducir?" << endl;
    cin >> n;
    // Validar que el número de elementos sea positivo
    if (n <= 0)
    {
        cout << "El número de elementos debe ser mayor que 0." << endl;
        return 1;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Número: " << i + 1 << ": ";
        cin >> arr[i];
    }
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma += arr[i];
    }

    double promedio = suma/n;
    cout << "El promedio de los números es: " << promedio << endl;

    return 0;
}