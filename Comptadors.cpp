// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "Comptadors.h"

Comptadors::Comptadors() : a_nEstabliments(0), a_places(0), a_estances(0) {}

void Comptadors::afegir(int places, int estances) {
    // TODO (persona A): sumar un establiment i les seves places i estances als comptadors
}

size_t Comptadors::nEstabliments() const {
    return a_nEstabliments;
}

int Comptadors::places() const {
    return a_places;
}

int Comptadors::estances() const {
    return a_estances;
}
