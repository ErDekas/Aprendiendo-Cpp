#include <iostream>
#include <vector>

using namespace std;

// Representación mediante matriz de adyacencia
void matrizAdyacencia() {
    int vertices = 4;
    vector<vector<int>> matriz(vertices, vector<int>(vertices, 0));

    matriz[0][1] = 1;
    matriz[1][2] = 1;
    matriz[2][3] = 1;

    cout << "Matriz de adyacencia:\n";
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

// Representación mediante lista de adyacencia
void listaAdyacencia() {
    int vertices = 4;
    vector<vector<int>> lista(vertices);

    lista[0].push_back(1);
    lista[1].push_back(2);
    lista[2].push_back(3);

    cout << "\nLista de adyacencia:\n";
    for (int i = 0; i < lista.size(); i++) {
        cout << i << ": ";
        for (int vecino : lista[i]) {
            cout << vecino << " ";
        }
        cout << endl;
    }
}

int main() {
    matrizAdyacencia();
    listaAdyacencia();

    return 0;
}
