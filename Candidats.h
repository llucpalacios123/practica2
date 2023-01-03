//
// Created by lluc9 on 03/01/2023.
//

#ifndef PRACTICA2_CANDIDATS_H
#define PRACTICA2_CANDIDATS_H


class Candidats {
public:
    Candidats(int ant, int max);
    int actual() const;
    bool esFi() const;
    void seguent();
private:
    int iCan;
    int nJoies;
};


#endif //PRACTICA2_CANDIDATS_H
