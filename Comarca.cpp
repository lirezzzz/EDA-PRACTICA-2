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

vector<MunicipiResult> Comarca::resultatMunicipis() const {
    vector<MunicipiResult> resultat;
    for (map<string, Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it)
        resultat.push_back(MunicipiResult(it->second.nom(), it->second.nEstabliments()));
    return resultat;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
    map<string, Municipi>::iterator it = a_municipis.find(codiMunicipi);
    if (it == a_municipis.end())        // municipi nou: el creem
        it = a_municipis.insert(make_pair(codiMunicipi, Municipi(codiMunicipi, nomMunicipi))).first;
    it->second.afegirEstabliment(e);
    actualitzarTop(e);

    // actualitzem el màxim: amb > estricte, en cas d'empat es queda el que hi ha arribat primer
    size_t n = it->second.nEstabliments();
    if (n > a_nMaxim) {
        a_nMaxim = n;
        a_codiMaxim = codiMunicipi;
    }
}

const Municipi &Comarca::municipiMaxim() const {
    return a_municipis.find(a_codiMaxim)->second;
}

list<Establiment> Comarca::establimentsDeMunicipi(const string &codiMunicipi) const {
    map<string, Municipi>::const_iterator it = a_municipis.find(codiMunicipi);
    if (it != a_municipis.end()) return it->second.establiments();
    return list<Establiment>();
}

CarrerResult Comarca::comptadorsDeCarrer(const string &codiMunicipi, const string &nomCarrer) const {
    map<string, Municipi>::const_iterator it = a_municipis.find(codiMunicipi);
    if (it != a_municipis.end()) return it->second.comptadorsDeCarrer(nomCarrer);
    return CarrerResult(nomCarrer, 0, 0, 0);
}

CarrerMesEstResult Comarca::carrerMesEstabliments() const {
    CarrerResult millor("", 0, 0, 0);
    string nomMunicipi;
    for (map<string, Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it) {
        CarrerResult r = it->second.carrerMesEstabliments();
        if (r.nEstabliments() > millor.nEstabliments()) {       // estricte: en empat es queda el municipi de codi més petit
            millor = r;
            nomMunicipi = it->second.nom();
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

