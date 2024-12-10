#include <iostream>
#include <string>

using namespace std;

class Temperatura {
private:
    double gradosCelsius;

public:
    Temperatura(double _gradosCelsius){
        gradosCelsius = _gradosCelsius;
    }

    double obtenerCelsius() {
        return gradosCelsius;
    }

    double obtenerFahrenheit() {
        return(gradosCelsius * 9.0/5.0) + 32;
    }

    double obtenerKelvin() {
        return(gradosCelsius + 273.15);
    }

    void setCelsius(double celsius) {
        gradosCelsius = celsius;
    }

    void setFarenheit(double farenheit) {
        gradosCelsius = (farenheit - 32) * 5.0 / 9.0;
    }

    void setKelvin(double kelvin) {
        gradosCelsius = kelvin - 273.15;
    }
};

int main() {
    Temperatura temp(0.25);

    cout << "Temperatura en Celsius: " << temp.obtenerCelsius() << "ºC" << endl;
    cout << "Temperatura en Farenheit: " << temp.obtenerFahrenheit() << "ºF" << endl;
    cout << "Temperatura en Kelvin: " << temp.obtenerKelvin() << " K" << endl;

    temp.setFarenheit(100.0);
    cout << "\nTemperatura Modificada: " << endl;
    cout << "Temperatura en Celsius: " << temp.obtenerCelsius() << "ºC" << endl;
    cout << "Temperatura en Farenheit: " << temp.obtenerFahrenheit() << "ºF" << endl;
    cout << "Temperatura en Kelvin: " << temp.obtenerKelvin() << " K" << endl;

    return 0;
}