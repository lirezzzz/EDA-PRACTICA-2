// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "Top10EstablimentResult.h"

Top10EstablimentResult::Top10EstablimentResult(const string &nom, int places, int estances)
    : a_nom(nom), a_places(places), a_estances(estances) {}

string Top10EstablimentResult::nom() const {
    return a_nom;
}

int Top10EstablimentResult::places() const {
    return a_places;
}

int Top10EstablimentResult::estances() const {
    return a_estances;
}
