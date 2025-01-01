#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class JuegoAhorcado {
private:
    string palabraSecreta;
    string palabraAdivinada;
    int intentosMaximos;
    int intentosRestantes;
    vector<char> letrasUsadas;

public:
    JuegoAhorcado(const string& palabra = "PROGRAMACION", int intentos = 6) {
        palabraSecreta = palabra;
        transform(palabraSecreta.begin(), palabraSecreta.end(), palabraSecreta.begin(), ::toupper);
        palabraAdivinada = string(palabraSecreta.length(), '_');
        intentosMaximos = intentos;
        intentosRestantes = intentos;
    }

    bool intentarLetra(char letra) {
        // Convertir a mayúscula
        letra = toupper(letra);

        // Verificar si la letra ya fue usada
        if (find(letrasUsadas.begin(), letrasUsadas.end(), letra) != letrasUsadas.end()) {
            cout << "Ya usaste esta letra!" << endl;
            return false;
        }

        letrasUsadas.push_back(letra);
        bool acierto = false;

        // Buscar la letra en la palabra
        for (size_t i = 0; i < palabraSecreta.length(); i++) {
            if (palabraSecreta[i] == letra) {
                palabraAdivinada[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentosRestantes--;
        }

        return acierto;
    }

    bool juegoTerminado() const {
        return intentosRestantes <= 0 || palabraAdivinada == palabraSecreta;
    }

    bool haGanado() const {
        return palabraAdivinada == palabraSecreta;
    }

    void mostrarEstado() const {
        cout << "\nPalabra: " << palabraAdivinada << endl;
        cout << "Intentos restantes: " << intentosRestantes << endl;
        cout << "Letras usadas: ";
        for (char letra : letrasUsadas) {
            cout << letra << " ";
        }
        cout << endl;
    }
};

int main() {
    JuegoAhorcado juego;
    char letra;

    cout << "¡Bienvenido al Juego del Ahorcado!" << endl;

    while (!juego.juegoTerminado()) {
        juego.mostrarEstado();
        
        cout << "\nIngresa una letra: ";
        cin >> letra;

        if (juego.intentarLetra(letra)) {
            cout << "¡Correcto!" << endl;
        } else {
            cout << "¡Incorrecto!" << endl;
        }
    }

    if (juego.haGanado()) {
        cout << "\n¡Felicitaciones! ¡Has ganado!" << endl;
    } else {
        cout << "\n¡Game Over! Mejor suerte la próxima vez." << endl;
    }

    return 0;
}