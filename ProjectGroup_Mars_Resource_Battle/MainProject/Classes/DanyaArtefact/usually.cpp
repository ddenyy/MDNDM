#include <iostream>
#include "usually.h"

using namespace std;

usually::usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 150;
    _cost = 20;
    _availability = "usually";
    _colour = "blue";
}

usually::usually(artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

usually::~usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
}

void usually::print() {
    cout << "Редкость : "<< _availability << "\n";
    cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
}