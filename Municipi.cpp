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
