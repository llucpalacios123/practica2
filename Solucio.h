//
// Created by llucp on 21/12/2022.
//

#ifndef PRACTICA2_SOLUCIO_H
#define PRACTICA2_SOLUCIO_H


#include <list>
#include "Candidats.h"
#include "Joia.h"

class Solucio {
public:

    Solucio();
    Solucio(const Solucio &o);
    ~Solucio();
    Solucio & operator=(const Solucio &o);
    Candidats inicialitzarCandidats() const;
    bool acceptable(Candidats iCan) const;
    void anotar(Candidats iCan);
    void desanotar(Candidats iCan);
    bool completa() const;
    void mostrar();
    int distancia();
    bool potSerMillor(const Solucio& optima) const;
    bool esMillor(const Solucio &opt) const;
    void afegirJoia(Joia joia);
    void afegirIncompatibilitats(string joia1, string joia2);
private:
    void reserva();
    void copia(const Solucio &s);
    void allibera();

    int nivell;
    int nFilas;
    int nColumnas;
    int valor;

    list<Joia> llistaJoies;
    list<pair<string,string>> llistaIncompatibilitats;

};


#endif //PRACTICA2_SOLUCIO_H
