//
// Created by lluc9 on 02/01/2023.
//

#ifndef PRACTICA2_JOIA_H
#define PRACTICA2_JOIA_H
#include<iostream>

using namespace std;

class Joia {
public:

Joia();
Joia(string nom, float pes, float volum);
string nom() const;
float pes() const;
float volum() const;


private:
    string _nom;
    float _pes, _volum;
};


#endif //PRACTICA2_JOIA_H
