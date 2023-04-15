#pragma once
#include "artefact.h"

class usually : public artefact {
public:
    usually();
    usually(artefact &ar);
    ~usually();
    void print();
};