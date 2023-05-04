#pragma once
#include "../../Additional_Libraries.h"

using namespace std;

class artefact {
protected:
    // координаты
    int _cord_x;
    int _cord_y;
    // вес
    int _weight;
    // стоимость(очки за доставку на базу)
    int _cost;
    // редкость
    string _availability;
    // цвет
    string _colour;
public:
    virtual ~artefact() = default;

	// геттеры
    int cord_x() { return _cord_x; }
    int cord_y() { return _cord_y; }
    int weight() { return _weight; }
    int cost() { return _cost; }
    string availability() { return _availability; }
    string colour() { return _colour; }

    // сетеры
    void set_cord_x(int cord_x) { _cord_x = cord_x; }
    void set_cord_y(int cord_y) { _cord_y = cord_y; }
    void set_weight(int weight) { _weight = weight; }
    void set_cost(int cost) { _cost = cost; }
    void set_availability(string availability) { _availability = availability; }
    void set_colour(string colour) { _colour = colour; }

    // печать (для проверки)
    virtual void print() = 0;

    //void operator=(artefact &ar);
};