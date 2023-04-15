#pragma once
#include "artefact.h"

class rare : public artefact {
private:
    // время видимости
    int _lifetime = 15;
    // увеличение грузоподъемности робота
    int _buff_lifting = 100;
public:
    rare();
    rare(artefact &ar);
    ~rare();
    void print();

    int lifetime() { return _lifetime; }
    int buff_lifting() { return _buff_lifting; }

    void set_lifetime(int lifetime) { _lifetime = lifetime; }
    void set_buff_lifting(int buff_lifting) { _buff_lifting = buff_lifting; }
};