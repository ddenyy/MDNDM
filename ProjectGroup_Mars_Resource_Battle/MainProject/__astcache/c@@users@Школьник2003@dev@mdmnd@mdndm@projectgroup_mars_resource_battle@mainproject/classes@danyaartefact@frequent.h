#pragma once
#include "artefact.h"

class frequent : public artefact {
public:
    frequent();
    frequent(artefact &ar);
    ~frequent();
    void print();
};