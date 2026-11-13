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
    for (list<Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it)
        resultat.push_back(MunicipiResult(it->nom(), it->nEstabliments()));
    return resultat;
}

void Comarca::afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                                const Establiment &e) {
    map<string, list<Municipi>::iterator>::iterator it = a_index.find(codiMunicipi);
    if (it == a_index.end()) {          // municipi nou: el posem al final de la llista
        a_municipis.push_back(Municipi(nomMunicipi));
        it = a_index.insert(make_pair(codiMunicipi, --a_municipis.end())).first;
    }
    it->second->afegirEstabliment(e);
    actualitzarTop(e);

    // actualitzem el màxim: amb > estricte, en cas d'empat es queda el que hi ha arribat primer
    size_t n = it->second->nEstabliments();
    if (n > a_nMaxim) {
        a_nMaxim = n;
        a_codiMaxim = codiMunicipi;
    }
}

const Municipi &Comarca::municipiMaxim() const {
    return *a_index.find(a_codiMaxim)->second;
}

list<Establiment> Comarca::establimentsDeMunicipi(const string &codiMunicipi) const {
    map<string, list<Municipi>::iterator>::const_iterator it = a_index.find(codiMunicipi);
    if (it != a_index.end()) return it->second->establiments();
    return list<Establiment>();
}

CarrerResult Comarca::comptadorsDeCarrer(const string &codiMunicipi, const string &nomCarrer) const {

    map<string, list<Municipi>::iterator>::const_iterator it = a_index.find(codiMunicipi);
    if (it != a_index.end()) return it->second->comptadorsDeCarrer(nomCarrer);
    return CarrerResult(nomCarrer, 0, 0, 0);
}

pair<int, int> Comarca::totalsMunicipi(const string &codiMunicipi) const {
    map<string, list<Municipi>::iterator>::const_iterator it = a_index.find(codiMunicipi);
    if (it != a_index.end()) return it->second->totals();

    return make_pair(0, 0);
}

CarrerResult Comarca::carrerMesEstablimentsDelMunicipi(const string &codiMunicipi) const {
    map<string, list<Municipi>::iterator>::const_iterator it = a_index.find(codiMunicipi);

    if (it != a_index.end()) return it->second->carrerMesEstabliments();

    return CarrerResult("", 0, 0, 0);
}

void Comarca::sumarUnitats(vector<int> &places, vector<size_t> &nEstabliments) const {
    for (list<Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it)
        it->sumarUnitats(places, nEstabliments);
}

void Comarca::sumarTitulars(vector<int> &places, vector<size_t> &nEstabliments) const {
    
    for (list<Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it)
        it->sumarTitulars(places, nEstabliments);
}

CarrerMesEstResult Comarca::carrerMesEstabliments() const {
    CarrerResult millor("", 0, 0, 0);
    string nomMunicipi;
    // mirem el millor carrer de cada municipi, en l'ordre del fitxer, i ens quedem amb el més gran
    for (list<Municipi>::const_iterator it = a_municipis.begin(); it != a_municipis.end(); ++it) {
        CarrerResult r = it->carrerMesEstabliments();
        if (r.nEstabliments() > millor.nEstabliments()) {       // amb > en empat guanya el primer que ha sortit
            millor = r;
            nomMunicipi = it->nom();
        }
    }
    return CarrerMesEstResult(a_nom, nomMunicipi, millor.carrer(), millor.nEstabliments());
}

top10EstablimentsResults Comarca::top10() const {
    top10EstablimentsResults resultat;
    // a_top ja està ordenat del millor al pitjor
    for (size_t i = 0; i < a_top.size(); i++)
        resultat.push_back(Top10EstablimentResult(a_top[i].nom(), a_top[i].places(), a_top[i].estances()));
    return resultat;
}

void Comarca::actualitzarTop(const Establiment &e) {
    ClauTop clau(e.places(), e.estances(), a_nEstabliments, e.nom());
    a_nEstabliments++;
    // si ja en tenim deu i aquest no és millor que l'últim, ni el mirem
    if (a_top.size() == 10 and !(clau < a_top.back())) return;
    // busquem on va perquè el vector es quedi ordenat, i si ens passem de deu traiem l'últim
    vector<ClauTop>::iterator it = a_top.begin();
    while (it != a_top.end() and *it < clau) ++it;                 // posició on va, mantenint l'ordre
    a_top.insert(it, clau);
    if (a_top.size() > 10) a_top.pop_back();                      // traiem el pitjor
}

