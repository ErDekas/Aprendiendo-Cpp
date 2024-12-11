#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    string sonido;
    void hacerSonido()
    {
        cout << sonido << endl;
    }
};

class Perro : public Animal
{
private:
    string nombre;

public:
    Perro(string _nombre, string _sonido)
    {
        sonido = _sonido;
        nombre = _nombre;
    }
    void hacerSonido()
    {
        cout << "El " << nombre << " dice: " << sonido << endl;
    }
};

class Gato : public Animal
{
private:
    string nombre;

public:
    Gato(string _nombre, string _sonido)
    {
        sonido = _sonido;
        nombre = _nombre;
    }
    void hacerSonido()
    {
        cout << "El " << nombre << " dice: " << sonido << endl;
    }
};

int main()
{
    Perro p1("Lola", "Guau");
    Gato g1("Toby", "Miau");
    p1.hacerSonido();
    g1.hacerSonido();
}