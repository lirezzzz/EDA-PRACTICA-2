/** @file Municipi.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "Municipi.h"

Municipi::Municipi() : a_nMillorCarrer(0) {}

Municipi::Municipi(const string &codi, const string &nom) : a_codi(codi), a_nom(nom), a_nMillorCarrer(0) {}

string Municipi::codi() const { 
    return a_codi; 
}

string Municipi::nom() const { 
    return a_nom; 
}

size_t Municipi::nEstabliments() const {
    return a_establiments.size();
}

void Municipi::afegirEstabliment(const Establiment &e) {
    a_establiments.push_back(e);
    Comptadors &c = a_carrers[e.carrer()];
    c.afegir(e.places(), e.estances());
    // només pot canviar el millor carrer el que acabem de comptar; en empat, ens quedem el que va primer per ordre alfabètic
    if (c.nEstabliments() > a_nMillorCarrer || (c.nEstabliments() == a_nMillorCarrer && e.carrer() < a_millorCarrer)) {
        a_nMillorCarrer = c.nEstabliments();
        a_millorCarrer = e.carrer();
    }
}

list<Establiment> Municipi::establiments() const {
    return a_establiments;
}

CarrerResult Municipi::comptadorsDeCarrer(const string &carrer) const {
   map<string, Comptadors>::const_iterator it = a_carrers.find(carrer);
   if (it!= a_carrers.end()){
    return CarrerResult(it->first,it->second.nEstabliments(),it->second.places(),it->second.estances());
   }
    return CarrerResult(carrer, 0, 0, 0);
}

CarrerResult Municipi::carrerMesEstabliments() const {
    return comptadorsDeCarrer(a_millorCarrer);      // si no hi ha establiments, a_millorCarrer és buit i dóna tot a 0
}

pair<int, int> Municipi::totals() const {
    pair<int, int> t(0, 0);
    for (map<string, Comptadors>::const_iterator it = a_carrers.begin(); it != a_carrers.end(); ++it) {
        t.first += it->second.places();
        t.second += it->second.estances();
    }
    return t;
}

void Municipi::sumarUnitats(vector<int> &places, vector<size_t> &nEstabliments) const {
    for (list<Establiment>::const_iterator it = a_establiments.begin(); it != a_establiments.end(); ++it) {
        places[it->unitat()] += it->places();
        nEstabliments[it->unitat()]++;
    }
}

void Municipi::sumarTitulars(vector<int> &places, vector<size_t> &nEstabliments) const {
    for (list<Establiment>::const_iterator it = a_establiments.begin(); it != a_establiments.end(); ++it) {
        places[it->titular()] += it->places();
        nEstabliments[it->titular()]++;
    }
}
