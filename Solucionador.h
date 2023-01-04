//
// Created by llucp on 21/12/2022.
//

#ifndef PRACTICA2_SOLUCIONADOR_H
#define PRACTICA2_SOLUCIONADOR_H


#include "Solucio.h"

class Solucionador {
public:
    Solucionador();
    bool solucionar(const Solucio &inicial);
    Solucio obtenirSolucio() const;
private:
    void trobarUnaSolucio();
    bool encertat;
    Solucio sol;
};


#endif //PRACTICA2_SOLUCIONADOR_H
