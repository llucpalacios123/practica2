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

bool llegir_fitxer(string fitxer, Solucio &solucio){
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
            solucio.afegirJoia(Joia(tokens[0], stof(tokens[1]), stof(tokens[2])));
        }

        getline(f,linia);

        contador_linia = stoi(linia);

        for(int i = 0; i< contador_linia; i++){
            getline(f,linia);
            stringstream ss(linia);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> tokens(begin, end);
        }

    }else{
        cout << "no es pot obrir el document" << endl;
    }

    return obrirDocument;

}

int main() {

    llegir_fitxer("t0.txt");
    return 0;
}
