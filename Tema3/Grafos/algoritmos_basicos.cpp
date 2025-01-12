#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

// Algoritmo de Dijkstra
void dijkstra(const vector<vector<pair<int, int>>>& grafo, int inicio) {
    int vertices = grafo.size();
    vector<int> distancia(vertices, INT_MAX);
    distancia[inicio] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        int distActual = pq.top().first;
        int actual = pq.top().second;
        pq.pop();

        for (const auto& [vecino, peso] : grafo[actual]) {
            if (distActual + peso < distancia[vecino]) {
                distancia[vecino] = distActual + peso;
                pq.push({distancia[vecino], vecino});
            }
        }
    }

    cout << "Distancias desde el nodo " << inicio << ": ";
    for (int d : distancia) {
        cout << d << " ";
    }
    cout << endl;
}

// Algoritmo de Kruskal
struct Arista {
    int origen, destino, peso;
    bool operator<(const Arista& otra) const {
        return peso < otra.peso;
    }
};

int find(vector<int>& padres, int x) {
    if (padres[x] != x) {
        padres[x] = find(padres, padres[x]);
    }
    return padres[x];
}

void kruskal(int vertices, vector<Arista>& aristas) {
    vector<int> padres(vertices);
    for (int i = 0; i < vertices; i++) {
        padres[i] = i;
    }

    sort(aristas.begin(), aristas.end());

    cout << "Árbol de expansión mínima (Kruskal):\n";
    for (const auto& arista : aristas) {
        int origenRaiz = find(padres, arista.origen);
        int destinoRaiz = find(padres, arista.destino);

        if (origenRaiz != destinoRaiz) {
            cout << arista.origen << " - " << arista.destino << " (Peso: " << arista.peso << ")\n";
            padres[origenRaiz] = destinoRaiz;
        }
    }
}

int main() {
    // Grafo para Dijkstra
    vector<vector<pair<int, int>>> grafo = {
        {{1, 4}, {2, 1}},
        {{2, 2}, {3, 5}},
        {{3, 8}},
        {}
    };
    dijkstra(grafo, 0);

    // Grafo para Kruskal
    vector<Arista> aristas = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    kruskal(4, aristas);

    return 0;
}
