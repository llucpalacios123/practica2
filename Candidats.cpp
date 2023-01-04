//
// Created by lluc9 on 03/01/2023.
//

#include "Candidats.h"

Candidats::Candidats(int ant, int max) {
    iCan = ant +1;
    nJoies = max;
}

bool Candidats::esFi() const {
    return iCan>nJoies;
}

int Candidats::actual() const {
    if (esFi())
        throw("No hi ha més candidats"); // excepcio
    return iCan;
}

void Candidats::seguent() {
    if (esFi())
        throw("No hi ha més candidats"); // excepcio
    iCan++;
}

