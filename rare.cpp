#include <iostream>
#include "rare.h"

using namespace std;

// конструктор
rare::rare() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 200;
    _cost = 40;
    _availability = "rare";
    _colour = "orange";
}

// конструктор копирования
rare::rare(artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

// деструктор
rare::~rare() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
    _lifetime = 0;
    _buff_lifting = 0;
}

// вывод для проверки
void rare::print() {
    cout << "Редкость : "<< _availability << "\n";
    cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
}

