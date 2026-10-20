// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

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

// ===== ZONA PERSONA A: opcions (d) i (f) =====

void Municipi::afegirCarrer(const string &carrer, int places, int estances) {
    // TODO (persona A): localitzar o crear l'entrada del carrer a a_carrers i comptar-hi l'establiment
    a_carrers[carrer].afegir(places, estances);
}

CarrerResult Municipi::comptadorsDeCarrer(const string &carrer) const {
    // TODO (persona A): cercar el carrer amb find (a un mètode const no es pot fer servir [])
    return CarrerResult(carrer, 0, 0, 0);
}

const map<string, Comptadors> &Municipi::carrers() const {
    return a_carrers;
}

// ===== FI ZONA PERSONA A =====
