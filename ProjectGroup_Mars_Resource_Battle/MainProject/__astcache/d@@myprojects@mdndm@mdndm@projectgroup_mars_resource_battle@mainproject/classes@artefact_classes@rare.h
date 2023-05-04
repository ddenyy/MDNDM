#pragma once
#include "artefact.h"

class rare : public artefact {
private:
    // время видимости
    int _lifetime = 15;
    // увеличение грузоподъемности робота
    int _buff_lifting = 100;
public:

    // конструктор
	rare()
	{
		_cord_x = 0;
		_cord_y = 0;
		_weight = 200;
		_cost = 40;
		_availability = "rare";
		_colour = "orange";
	}


    // конструктор копирования
	rare(artefact &ar) {
		_cord_x = ar.cord_x();
		_cord_y = ar.cord_y();
		_weight = ar.weight();
		_cost = ar.cost();
		_availability = ar.availability();
		_colour = ar.colour();
	}
    // деструктор
	~rare() {
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
	void print() {
		cout << "Редкость : "<< _availability << "\n";
		cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
	}

    int lifetime() { return _lifetime; }
    int buff_lifting() { return _buff_lifting; }

    void set_lifetime(int lifetime) { _lifetime = lifetime; }
    void set_buff_lifting(int buff_lifting) { _buff_lifting = buff_lifting; }
};