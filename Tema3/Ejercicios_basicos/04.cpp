#include <iostream>

class NodoDoble {
public:
    int data;
    NodoDoble* prev;
    NodoDoble* next;

    NodoDoble(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class ListaDoble {
private:
    NodoDoble* head;
    NodoDoble* tail;

public:
    ListaDoble() : head(nullptr), tail(nullptr) {}

    void agregar(int val) {
        NodoDoble* nuevoNodo = new NodoDoble(val);
        if (!head) {
            head = tail = nuevoNodo;
        } else {
            tail->next = nuevoNodo;
            nuevoNodo->prev = tail;
            tail = nuevoNodo;
        }
    }

    void eliminar(int val) {
        NodoDoble* temp = head;
        while (temp) {
            if (temp->data == val) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void imprimir() {
        NodoDoble* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    ListaDoble lista;
    lista.agregar(1);
    lista.agregar(2);
    lista.agregar(3);
    lista.imprimir(); // Output: 1 2 3

    lista.eliminar(2);
    lista.imprimir(); // Output: 1 3

    return 0;
}