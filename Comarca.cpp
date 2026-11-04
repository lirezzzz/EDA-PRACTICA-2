/** @file Comarca.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "Comarca.h"

Comarca::Comarca() : a_codi(0), a_nEstabliments(0), a_nMaxim(0) {}

Comarca::Comarca(int codi, const string &nom) : a_codi(codi), a_nom(nom), a_nEstabliments(0), a_nMaxim(0) {}

int Comarca::codi() const {
    return a_codi;
}

string Comarca::nom() const {
    return a_nom;
}

bool Comarca::buida() const {
    return a_municipis.empty();
}

const vector<Municipi> &Comarca::municipis() const {
    return a_municipis;
}

int Comarca::cercaDicotomica(const string &codiMunicipi) const {
    int pos;
    return cercaDicotomica(codiMunicipi, pos);
}

int Comarca::cercaDicotomica(const string &codiMunicipi, int &pos) const {
    int esq = 0;
    int dre = int(a_municipis.size()) - 1;
    while (esq <= dre) {
        int mig = esq + (dre - esq) / 2;
        const string &codiMig = a_municipis[mig].codi();
        if (codiMig == codiMunicipi) {
            pos = mig;
            return mig;
        }
        if (codiMig < codiMunicipi) {
            esq = mig + 1;
        } else {
            dre = mig - 1;
        }
    }
    pos = esq;
    return -1;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
    int pos;
    if (cercaDicotomica(codiMunicipi, pos) == -1) { // no existeix: pos és on ha d'anar per mantenir l'ordre
        a_municipis.insert(a_municipis.begin() + pos, Municipi(codiMunicipi, nomMunicipi));
    }
    a_municipis[pos].afegirEstabliment(e);
    actualitzarTop(e);

    // actualitzem el màxim: amb > estricte, en cas d'empat es queda el que hi ha arribat primer
    size_t n = a_municipis[pos].nEstabliments();
    if (n > a_nMaxim) {
        a_nMaxim = n;
        a_codiMaxim = codiMunicipi;
    }
}

const Municipi &Comarca::municipiMaxim() const {
    // guardem el codi i no la posició perquè els insert desplacen els municipis dins el vector
    return a_municipis[cercaDicotomica(a_codiMaxim)];
}

list<Establiment> Comarca::establimentsDeMunicipi(const string &codiMunicipi) const{
    int pos = cercaDicotomica(codiMunicipi);
    if (pos != -1) return a_municipis[pos].establiments();
    return list<Establiment>();
}

CarrerMesEstResult Comarca::carrerMesEstabliments() const {
    CarrerResult millor("", 0, 0, 0);
    string nomMunicipi;
    for (size_t j = 0; j < a_municipis.size(); j++) {
        CarrerResult r = a_municipis[j].carrerMesEstabliments();
        if (r.nEstabliments() > millor.nEstabliments()) {       // estricte: en empat es queda el municipi de codi més petit
            millor = r;
            nomMunicipi = a_municipis[j].nom();
        }
    }
    return CarrerMesEstResult(a_nom, nomMunicipi, millor.carrer(), millor.nEstabliments());
}

top10EstablimentsResults Comarca::top10() const {
    top10EstablimentsResults resultat;

    // Recórrer el vector, ja ordenat del millor al pitjor
    for (size_t i = 0; i < a_top.size(); i++)
        resultat.push_back(Top10EstablimentResult(a_top[i].nom(), a_top[i].places(), a_top[i].estances()));

    return resultat;
}

void Comarca::actualitzarTop(const Establiment &e) {
    ClauTop clau(e.places(), e.estances(), a_nEstabliments, e.nom());
    a_nEstabliments++;
    if (a_top.size() == 10 && !(clau < a_top.back())) return;   // no millora el pitjor dels deu
    vector<ClauTop>::iterator it = a_top.begin();
    while (it != a_top.end() && *it < clau) ++it;                 // posició on va, mantenint l'ordre
    a_top.insert(it, clau);
    if (a_top.size() > 10) a_top.pop_back();                      // traiem el pitjor
}

