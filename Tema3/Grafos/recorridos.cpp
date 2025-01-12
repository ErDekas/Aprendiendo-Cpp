#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Clase para representar un grafo
class Grafo {
private:
    int vertices; // Número de vértices
    vector<vector<int>> adj; // Lista de adyacencia

public:
    // Constructor
    Grafo(int v) : vertices(v), adj(v) {}

    // Método para agregar una arista
    void agregarArista(int origen, int destino) {
        adj[origen].push_back(destino);
        adj[destino].push_back(origen); // Para grafos no dirigidos
    }

    // BFS - Búsqueda en anchura
    void BFS(int inicio) {
        vector<bool> visitado(vertices, false);
        queue<int> cola;
        cola.push(inicio);
        visitado[inicio] = true;

        cout << "Recorrido BFS: ";
        while (!cola.empty()) {
            int actual = cola.front();
            cola.pop();
            cout << actual << " ";

            for (int vecino : adj[actual]) {
                if (!visitado[vecino]) {
                    cola.push(vecino);
                    visitado[vecino] = true;
                }
            }
        }
        cout << endl;
    }

    // DFS - Búsqueda en profundidad
    void DFS(int inicio) {
        vector<bool> visitado(vertices, false);
        stack<int> pila;
        pila.push(inicio);

        cout << "Recorrido DFS: ";
        while (!pila.empty()) {
            int actual = pila.top();
            pila.pop();

            if (!visitado[actual]) {
                cout << actual << " ";
                visitado[actual] = true;

                for (int vecino : adj[actual]) {
                    if (!visitado[vecino]) {
                        pila.push(vecino);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Grafo g(6);
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 3);
    g.agregarArista(1, 4);
    g.agregarArista(2, 5);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
