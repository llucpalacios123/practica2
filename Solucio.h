//
// Created by llucp on 21/12/2022.
//

#ifndef PRACTICA2_SOLUCIO_H
#define PRACTICA2_SOLUCIO_H


#include <list>
#include <vector>
#include "Candidats.h"
#include "Joia.h"
#include <iomanip>

class Solucio {
public:
    Solucio();
    Solucio(vector<Joia> joies, list<pair<int, int>> incompatibilitats, float pes, float volum, int numViatges);
    Solucio(const Solucio &o);
    ~Solucio();
    Solucio & operator=(const Solucio &o);
    Candidats inicialitzarCandidats() const;
    bool acceptable(Candidats iCan) const;
    void anotar(Candidats iCan);
    void desanotar(Candidats iCan);
    bool completa() const;
    void mostrar();
    bool potSerMillor(const Solucio& optima) const;
    bool esMillor(const Solucio &opt) const;
private:
    void reserva();
    void copia(const Solucio &s);
    void allibera();
    float pesViatge(int n) const;
    float volumViatge(int n) const;

    int nivell;
    int viatge;
    bool * agafades;
    vector<vector<int>> viatges;
    vector<Joia> llistaJoies;
    list<pair<int,int>> llistaIncompatibilitats;
    float pesMaxim;
    float volumMaxim;
    int nViatges;
    int variança;
    int nJoies;
    int * agafats;
    int joiesRevisades;
};


#endif //PRACTICA2_SOLUCIO_H
