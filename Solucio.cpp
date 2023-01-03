//
// Created by llucp on 21/12/2022.
//

#include "Solucio.h"

void Solucio::afegirJoia(Joia joia) {
    llistaJoies.push_back(joia);
}

bool Solucio::potSerMillor(const Solucio &optima) const {
    return false;
}

void Solucio::afegirIncompatibilitats(string joia1, string joia2) {
    llistaIncompatibilitats.push_back(make_pair(joia1,joia2));
}

Solucio::Solucio() {

}

Solucio::~Solucio() {

}

Solucio::Solucio(const Solucio &o) {

}

Solucio &Solucio::operator=(const Solucio &o) {
    return <#initializer#>;
}

Candidats Solucio::inicialitzarCandidats() const {
    return Candidats(0, 0);
}

bool Solucio::acceptable(Candidats iCan) const {
    return false;
}

void Solucio::anotar(Candidats iCan) {

}

void Solucio::desanotar(Candidats iCan) {

}

bool Solucio::completa() const {
    return false;
}

void Solucio::mostrar() {

}


