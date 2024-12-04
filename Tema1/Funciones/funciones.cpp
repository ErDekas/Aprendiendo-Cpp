#include <iostream>

using namespace std;

/*
tipo_retorno nombre_funcion(parámetros) {
    Código de la funcion

    return valor; // Opcional, depende de la función
}

*/

int sumar(int a, int b){
    return a + b;
}
int main() {
    int resultado = sumar(5, 6);
    cout << "Resultado de sumar 5 + 6: " << resultado << endl;

    return 0;
}