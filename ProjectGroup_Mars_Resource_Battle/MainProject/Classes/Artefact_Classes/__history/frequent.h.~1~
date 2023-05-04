#pragma once
#include "artefact.h"
#include "../../Additional_Libraries.h"


class frequent : public artefact {
public:

	frequent()
	{
		_cord_x = 0;
		_cord_y = 0;
		_weight = 100;
		_cost = 10;
		_availability = "frequent";
		_colour = "gray";
	}

	frequent(artefact &ar)
	 {
		_cord_x = ar.cord_x();
		_cord_y = ar.cord_y();
		_weight = ar.weight();
		_cost = ar.cost();
		_availability = ar.availability();
		_colour = ar.colour();
	}

	~frequent() {
		_cord_x = 0;
		_cord_y = 0;
		_weight = 0;
		_cost = 0;
		_availability = "";
		_colour = "";
	}
	void print() {
		std::cout << "Редкость : "<< _availability << "\n";
		std::cout << "Координаты : " << _cord_x << " ; " << _cord_y << "\n";
	}
};