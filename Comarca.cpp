// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#include "Comarca.h"

Comarca::Comarca() : a_codi(0), a_nMaxim(0) {}

Comarca::Comarca(int codi, const string &nom) : a_codi(codi), a_nom(nom), a_nMaxim(0) {}

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

bool Comarca::existeixMunicipi(const string &codiMunicipi) const {
    return cercaDicotomica(codiMunicipi) != -1;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
    int pos;
    if (cercaDicotomica(codiMunicipi, pos) == -1) { // no existeix: pos és on ha d'anar per mantenir l'ordre
        a_municipis.insert(a_municipis.begin() + pos, Municipi(codiMunicipi, nomMunicipi));
    }
    size_t index = a_establiments.size();
    a_establiments.push_back(e);
    a_municipis[pos].afegirEstabliment(index);
    a_municipis[pos].afegirCarrer(e.carrer(), e.places(), e.estances());   // enllaç opcions (d) i (f), zona persona A
    actualitzarTop(index, e);                                              // enllaç opció (g), zona persona B

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
    list<Establiment> resultat; 
    int pos = cercaDicotomica(codiMunicipi);
    if (pos!=-1){
       const vector<size_t> &indexs = a_municipis[pos].indexs();
       for (size_t i=0; i<indexs.size(); i++){
            resultat.push_back(a_establiments[indexs[i]]);
       }
    }
    return resultat;
}

// ===== ZONA PERSONA B: opció (g) =====

top10EstablimentsResults Comarca::top10() const {
    top10EstablimentsResults resultat;

    // Recórrer el set ja ordenat del millor al pitjor
    for (const ClauTop &clau : a_top) {
        const Establiment &e = a_establiments[clau.index()];
        resultat.push_back(Top10EstablimentResult(
            e.nom(),
            e.places(),
            e.estances()
        ));
    }

    return resultat;
}


void Comarca::actualitzarTop(size_t index, const Establiment &e) {
    // Inserim la nova clau al set
    a_top.insert(ClauTop(e.places(), e.estances(), index));

    // Si hi ha més de 10 elements, eliminem el pitjor (l'últim del set)
    if (a_top.size() > 10) {
        auto it = a_top.end();
        --it;  // apunta al pitjor establiment
        a_top.erase(it);
    }
}


// ===== FI ZONA PERSONA B =====
