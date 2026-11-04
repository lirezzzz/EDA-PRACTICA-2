// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "Municipi.h"

Municipi::Municipi() {}

Municipi::Municipi(const string &codi, const string &nom) : a_codi(codi), a_nom(nom) {}

string Municipi::codi() const { 
    return a_codi; 
}

string Municipi::nom() const { 
    return a_nom; 
}

size_t Municipi::nEstabliments() const {
    return a_indexs.size();
}

const vector<size_t> &Municipi:: indexs() const{ 
     return a_indexs;
}

void Municipi::afegirEstabliment(size_t index) {
    a_indexs.push_back(index);
}

void Municipi::afegirCarrer(const string &carrer, int places, int estances) {
    a_carrers[carrer].afegir(places, estances);
}

CarrerResult Municipi::comptadorsDeCarrer(const string &carrer) const {
   map<string, Comptadors>::const_iterator it = a_carrers.find(carrer);
   if (it!= a_carrers.end()){
    return CarrerResult(it->first,it->second.nEstabliments(),it->second.places(),it->second.estances());
   }
    return CarrerResult(carrer, 0, 0, 0);
}

const map<string, Comptadors> &Municipi::carrers() const {
    return a_carrers;
}

