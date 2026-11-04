/** @file Municipi.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

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
    return a_establiments.size();
}

void Municipi::afegirEstabliment(const Establiment &e) {
    a_establiments.push_back(e);
    a_carrers[e.carrer()].afegir(e.places(), e.estances());
}

list<Establiment> Municipi::establiments() const {
    return list<Establiment>(a_establiments.begin(), a_establiments.end());
}

CarrerResult Municipi::comptadorsDeCarrer(const string &carrer) const {
   map<string, Comptadors>::const_iterator it = a_carrers.find(carrer);
   if (it!= a_carrers.end()){
    return CarrerResult(it->first,it->second.nEstabliments(),it->second.places(),it->second.estances());
   }
    return CarrerResult(carrer, 0, 0, 0);
}

CarrerResult Municipi::carrerMesEstabliments() const {
    CarrerResult millor("", 0, 0, 0);
    for (map<string, Comptadors>::const_iterator it = a_carrers.begin(); it != a_carrers.end(); ++it) {
        if (it->second.nEstabliments() > millor.nEstabliments())      // estricte: en empat es queda el primer per ordre alfabètic
            millor = CarrerResult(it->first, it->second.nEstabliments(), it->second.places(), it->second.estances());
    }
    return millor;
}

