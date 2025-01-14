#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath> // Para operaciones como pow
using namespace std;

// Función para evaluar una expresión postfija
double evaluatePostfix(const string& expression) {
    stack<double> s; // Pila para almacenar los operandos

    stringstream ss(expression); // Flujo para dividir la expresión
    string token;

    while (ss >> token) {
        // Si el token es un número, lo empujamos a la pila
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
            s.push(stod(token)); // Convertir a double y empujar a la pila
        }
        // Si el token es un operador
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            if (s.size() < 2) {
                throw runtime_error("Expresión inválida: no hay suficientes operandos.");
            }
            // Sacar los dos operandos superiores de la pila
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            // Evaluar el operador y empujar el resultado
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") {
                if (b == 0) throw runtime_error("Error: División por cero.");
                s.push(a / b);
            }
            else if (token == "^") s.push(pow(a, b));
        }
        else {
            throw runtime_error("Expresión inválida: token desconocido '" + token + "'.");
        }
    }

    // El resultado final debería estar en la cima de la pila
    if (s.size() != 1) {
        throw runtime_error("Expresión inválida: operandos restantes en la pila.");
    }

    return s.top();
}

// Ejemplo de uso
int main() {
    string expression;

    cout << "Introduce una expresión en notación postfija (separada por espacios): ";
    getline(cin, expression);

    try {
        double result = evaluatePostfix(expression);
        cout << "Resultado: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
