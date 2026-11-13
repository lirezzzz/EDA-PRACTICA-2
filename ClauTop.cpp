/** @file ClauTop.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "ClauTop.h"

ClauTop::ClauTop(int places, int estances, size_t ordre, const string &nom)
    : a_places(places), a_estances(estances), a_ordre(ordre), a_nom(nom) {}

int ClauTop::places() const {
    return a_places;
}

int ClauTop::estances() const {
    return a_estances;
}

string ClauTop::nom() const {
    return a_nom;
}

bool ClauTop::operator<(const ClauTop &altra) const {
    // Més places primer (descendent)
    if (a_places != altra.a_places)
        return a_places > altra.a_places;

    // En cas d'empat, més estances primer (descendent)
    if (a_estances != altra.a_estances)
        return a_estances > altra.a_estances;

    // Si tornen a empatar, l'ordre més petit primer (ascendent)
    return a_ordre < altra.a_ordre;
}

