/** @file Top10EstablimentResult.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

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
