//
// Created by llucp on 21/12/2022.
//

#include "Solucio.h"

bool Solucio::potSerMillor(const Solucio &optima) const {
    return false;
}

Solucio::Solucio(vector<Joia> joies, list<pair<int, int>> incompatibilitats, float pes, float volum, int numViatges) {
    llistaJoies = joies;
    llistaIncompatibilitats = incompatibilitats;
    pesMaxim = pes;
    volumMaxim = volum;
    nViatges = numViatges;
    nJoies = llistaJoies.size();
    nViatges = numViatges;
    viatge = 0;
    viatges.push_back(vector<int>());
    nivell = 0;
    reserva();
    agafats[0] = 0;
}

Solucio::~Solucio() {

}

Solucio::Solucio(const Solucio &o) {

}

Candidats Solucio::inicialitzarCandidats() const {
    return Candidats(agafats[nivell], nJoies);
}

bool Solucio::acceptable(Candidats iCan) const {
    float pes = 0, volum = 0;
    bool acceptable = false;
    /*for(auto const jv : viatges[viatge]){
        pes += llistaJoies[jv].pes();
        volum += llistaJoies[jv].volum();
    }

    if(pes + llistaJoies[iCan.actual()].pes() <= pesMaxim
    and pes + llistaJoies[iCan.actual()].volum() <= volumMaxim
    and agafades[iCan.actual()]){
        acceptable = true;
    }*/

    return llistaJoies[iCan.actual()].pes() <= pesMaxim
        and llistaJoies[iCan.actual()].volum() <= volumMaxim
        and !agafades[iCan.actual()];
}

void Solucio::anotar(Candidats iCan) {
    float pes = 0, volum = 0;
    for(auto const jv : viatges[viatge]){
        pes += llistaJoies[jv].pes();
        volum += llistaJoies[jv].volum();
    }

    if(pes + llistaJoies[iCan.actual()].pes() <= pesMaxim
       and volum + llistaJoies[iCan.actual()].volum() <= volumMaxim){
       viatges[viatge].push_back(iCan.actual());
    }else{
        viatges.push_back(vector<int>());
        viatge++;
        viatges[viatge].push_back(iCan.actual());
    }
    agafats[nivell] = iCan.actual();
    nivell++;
    agafades[iCan.actual()] = true;
}

void Solucio::desanotar(Candidats iCan) {
    agafats[nivell] = 0;
    nivell--;
    agafades[iCan.actual()] = true;
    viatges[viatge].pop_back();
}

bool Solucio::completa() const {
    return nivell >= nJoies;
}

void Solucio::mostrar() {
    for(int i = 0; i < viatges.size() ; i++){
        cout << "viatge " + i << endl ;
        for(const auto j: viatges[i]){
            cout << llistaJoies[j].nom() << endl;
        }
    }
}

bool Solucio::esMillor(const Solucio &opt) const {
    return false;
}

void Solucio::reserva() {
    agafats = new int[nJoies+1];
}

void Solucio::copia(const Solucio &s) {
    llistaJoies = s.llistaJoies;
    llistaIncompatibilitats = s.llistaIncompatibilitats;
    pesMaxim = s.pesMaxim;
    volumMaxim = s.volumMaxim;
    nViatges = s.nViatges;
    nJoies = s.nJoies;
    viatges = s.viatges;
    viatge = s.viatge;
    nivell = s.nivell;
    agafats = s.agafats;
}

void Solucio::allibera() {

}

Solucio &Solucio::operator=(const Solucio &o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

Solucio::Solucio() {}


