#pragma once
#include "artefact.h"

class usually : public artefact {
public:

	usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 150;
    _cost = 20;
    _availability = "usually";
    _colour = "blue";
}

	usually(artefact &ar) {
    _cord_x = ar.cord_x();
    _cord_y = ar.cord_y();
    _weight = ar.weight();
    _cost = ar.cost();
    _availability = ar.availability();
    _colour = ar.colour();
}

	~usually() {
    _cord_x = 0;
    _cord_y = 0;
    _weight = 0;
    _cost = 0;
    _availability = "";
    _colour = "";
}

    void print() {
	cout << "�������� : "<< _availability << "\n";
    cout << "���������� : " << _cord_x << " ; " << _cord_y << "\n";
}
};