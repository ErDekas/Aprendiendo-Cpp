#include <iostream>

using namespace std;

void intercambiar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int x = 5;
    int y = 7;

    cout << "Antes del intercambio: " << endl;
    cout << "X: " << x << ", Y: " << y << endl;

    intercambiar(&x, &y);
    
    cout << "Después del intercambio: " << endl;
    cout << "X: " << x << ", Y: " << y << endl;
}