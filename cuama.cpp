#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


class Nodo {
private:
int data;
string data1;
Nodo *link;
public:
Nodo(int data,string data1);
Nodo(int data, Nodo*link);
int getHabitacion() const;
string getHuesped() const;
Nodo* getLink() const;

void setData(int dato);
void setLink(Nodo* link);
};//fin de la class Nodo
//Defininimos los métodos de la clase Nodo
Nodo::Nodo(int data,string data1) {
    this->data=data;
    this->data1=data1;
    this->link= 0;
}
Nodo::Nodo(int data, Nodo* link) {
    this->data=data;
    this->link= link;
}

string Nodo::getHuesped() const {
    return this->data1;
}
int Nodo::getHabitacion() const {
    return this->data;
}

Nodo* Nodo::getLink() const {
    return this->link;
}

void Nodo::setData(int dato) {
    data=dato;
}


void Nodo::setLink(Nodo *link) {
    this->link=link;
}



void nuevoHuesped(Nodo *&head) {
    string nombre;
    int habitacion;

    cout << "Ingrese nombre huesped ";
    cin >> nombre;
    cout << "Ingrese numero de habitacion: ";
    cin >> habitacion;


    Nodo *nuevo_nodo = new Nodo(habitacion,nombre);
    head = nuevo_nodo;



    ofstream output_file("archivo.txt", ios::app);
    output_file << nombre << endl;
    output_file << habitacion << endl;
    output_file.close();

    cout << "Huesped " << nombre << " se añadio satisfactoriamente!" << endl;
}

void buscarHuesped(Nodo *head) {
    string huespedBusqueda;
    cout << "Ingrese el nombre del huesped a busscar: ";
    cin >> huespedBusqueda;

    Nodo *actual = head;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getHuesped() == huespedBusqueda ) {
            encontrado = true;
            cout << "Huesped " << actual->getHuesped() << " esta en la habitacion " << actual->getHabitacion() << endl;
            break;
        }
        actual = actual->getLink();
    }

    if (!encontrado) {
        cout << "Huesped no encontrado." << endl;
    }
}


void mostrarAlfabeticamente(Nodo *head) {

    vector<string> nombres_huespedes;
    Nodo *actual = head;
    while (actual != nullptr) {
        nombres_huespedes.push_back(actual->getHuesped());
        actual = actual->getLink();
    }
    sort(nombres_huespedes.begin(), nombres_huespedes.end());


    cout << "Lista de huespedes en orden alfabetico:" << endl;
    for (string nombre : nombres_huespedes) {
        actual = head;
        while (actual != nullptr) {
            if (actual->getHuesped() == nombre) {
                cout << "Huesped: " << actual->getHuesped() << ", Habitacion: " << actual->getHabitacion() << endl;
                break;
            }
            actual = actual->getLink();
        }
    }
}

void mostrarenOrden(Nodo* head) {
    Nodo* actual = head;
    while (actual != nullptr) {
        cout << "Nombre Huesped: " << actual->getHuesped() << endl;
        cout << "Numero Habitacion: " << actual->getHabitacion() << endl;
        actual = actual->getLink()->getLink();
    }
}

int revisarDisponibilidad(Nodo* head, int numeroHabitacion) {
    Nodo* actual = head;
    while (actual != nullptr) {
        if (actual->getLink()->getHabitacion() == numeroHabitacion) {

            Nodo* anterior = actual->getLink()->getLink();
            Nodo* siguiente = actual->getLink()->getLink()->getLink();
            if (anterior != nullptr && anterior->getLink()->getHabitacion() != numeroHabitacion) {
                cout << "Habitacion " << numeroHabitacion << " esta ocupada. Ofrecemos la habitacion: " << anterior->getLink()->getHabitacion() << endl;
                return anterior->getLink()->getHabitacion();
            }
            if (siguiente != nullptr && siguiente->getLink()->getHabitacion() != numeroHabitacion) {

                cout << "Habitacion " << numeroHabitacion << " esta ocupada. Ofrecemos la habitacion: " << siguiente->getLink()->getHabitacion() << endl;
                return siguiente->getLink()->getHabitacion();
            }

            cout << "Las habitaciones contiguas a la seleccionada estan ocupadas. Por favor seleccione otra habitacion: ";
            cin >> numeroHabitacion;
            return revisarDisponibilidad(head, numeroHabitacion);
        }
        actual = actual->getLink()->getLink();
    }

    cout << "Numero habitacio no encontrado. Ingrese otro numero: ";
    cin >> numeroHabitacion;
    return revisarDisponibilidad(head, numeroHabitacion);
}
int main() {
    string filename = "archivo.txt";
    ifstream input_file(filename);

    Nodo *head = nullptr;

    int dato1;
    string dato2;
    while (input_file >> dato1 >> dato2) {
        Nodo *new_node = new Nodo(dato1, dato2);
        head = new_node;

    }


}
