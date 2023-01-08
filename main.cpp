#include <iostream>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iterator>
#include <vector>
#include <sstream>
#include "Solucio.h"
#include "Solucionador.h"
#include "Joia.h"

using namespace std;

void afegirIncompatibilitats(string joia1, string joia2, list<pair<int,int>> &incompatibilitats, const vector<Joia> &joies){
    int j1 = -1, j2 = -1;
    bool trobat1 = false, trobat2 = false;
    for(int i = 0; i<joies.size() or (!trobat1 and !trobat2);i++){
        if(joia1 == joies[i].nom()){
            trobat1 = true;
            j1 = i;
        }
        if(joia2 == joies[i].nom()){
            trobat2 = true;
            j2 = i;
        }
    }
    incompatibilitats.push_back(make_pair(j1, j2));
}

bool llegir_fitxer(string fitxer, vector<Joia> &joies, list<pair<int,int>> &incompatibilitats){
    ifstream f;
    int contador_linia = 0;
    string s;

    string linia;
    f.open(fitxer);

    bool obrirDocument = true;

    if (!f.fail()){
        getline(f,linia);

        contador_linia = stoi(linia);

        for(int i = 0; i< contador_linia; i++){
            getline(f,linia);
            stringstream ss(linia);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> tokens(begin, end);
            joies.push_back(Joia(tokens[0], stof(tokens[1]), stof(tokens[2])));
        }

        getline(f,linia);

        contador_linia = stoi(linia);

        for(int i = 0; i< contador_linia; i++){
            getline(f,linia);
            stringstream ss(linia);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> tokens(begin, end);
            afegirIncompatibilitats(tokens[0], tokens[1], incompatibilitats, joies);
        }

    }else{
        cout << "no es pot obrir el document" << endl;
    }

    return obrirDocument;

}



int main() {
    vector<Joia> joies;
    list<pair<int,int>> incompatibilitats;
    llegir_fitxer("t0.txt", joies, incompatibilitats);
    Solucio solucio(joies, incompatibilitats, 25, 40, 5);
    Solucionador s;
    s.solucionar(solucio);
    return 0;
}
