//
// Created by lluc9 on 02/01/2023.
//

#include "Joia.h"

Joia::Joia() {

}

string Joia::nom() const {
    return _nom;
}

float Joia::pes() const {
    return _pes;
}

float Joia::volum() const {
    return _volum;
}

Joia::Joia(string nom, float pes, float volum) {

    _nom = nom;
    _pes = pes;
    _volum = volum;

}
