#include <iostream>
#include <string>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructor
    Fecha(int _dia, int _mes, int _anio) {
        dia = _dia;
        mes = _mes;
        anio = _anio;
    }

    // Método para verificar si un año es bisiesto
    bool esBisiesto(int anio) const {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    // Método para obtener los días en un mes
    int diasEnMes(int mes, int anio) const {
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return esBisiesto(anio) ? 29 : 28;
            default:
                throw invalid_argument("Mes inválido.");
        }
    }

    // Método para avanzar un día
    void avanzarUnDia() {
        dia++;
        if (dia > diasEnMes(mes, anio)) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                anio++;
            }
        }
    }

    // Método para retroceder un día
    void retrocederUnDia() {
        dia--;
        if (dia < 1) {
            mes--;
            if (mes < 1) {
                mes = 12;
                anio--;
            }
            dia = diasEnMes(mes, anio);
        }
    }

    // Método para mostrar la fecha
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

int main() {
    Fecha fecha(1, 1, 2024);

    cout << "Fecha inicial: ";
    fecha.mostrar();

    fecha.avanzarUnDia();
    cout << "Después de avanzar un día: ";
    fecha.mostrar();

    fecha.retrocederUnDia();
    fecha.retrocederUnDia();
    cout << "Después de retroceder dos días: ";
    fecha.mostrar();

    return 0;
}
