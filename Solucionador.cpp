//
// Created by llucp on 21/12/2022.
//

#include "Solucionador.h"

bool Solucionador::solucionar(const Solucio &inicial) {
    encertat = false;
    sol = inicial;
    trobarUnaSolucio();
    return encertat;
}

Solucio Solucionador::obtenirSolucio() const {
    if (not encertat)
        throw("No s’ha trobat la solució");
    return sol;
}

void Solucionador::trobarUnaSolucio() {
    Candidats iCan = sol.inicialitzarCandidats();
    while (not iCan.esFi() and not encertat) {
        if (sol.acceptable(iCan)) {
            sol.anotar(iCan);
            if (not sol.completa()) {
                trobarUnaSolucio();
                if (not encertat)
                    sol.desanotar(iCan);
            } else
                encertat = true;
        }
        iCan.seguent();
    }

}
