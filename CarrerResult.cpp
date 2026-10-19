// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "CarrerResult.h"

CarrerResult::CarrerResult(const string &carrer, size_t nEstabliments, int places, int estances)
    : a_carrer(carrer), a_nEstabliments(nEstabliments), a_places(places), a_estances(estances) {}

string CarrerResult::carrer() const {
    return a_carrer;
}

size_t CarrerResult::nEstabliments() const {
    return a_nEstabliments;
}

int CarrerResult::places() const {
    return a_places;
}

int CarrerResult::estances() const {
    return a_estances;
}
