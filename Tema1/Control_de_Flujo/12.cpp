#include <iostream>

using namespace std;

int main() {
    int n;
    int aumento = 0;
    cout << "Introduce un número" << endl;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        aumento += i;
    }
    cout << aumento << endl;
}