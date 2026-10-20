// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "ClauTop.h"

ClauTop::ClauTop(int places, int estances, size_t index)
    : a_places(places), a_estances(estances), a_index(index) {}

int ClauTop::places() const {
    return a_places;
}

int ClauTop::estances() const {
    return a_estances;
}

size_t ClauTop::index() const {
    return a_index;
}

bool ClauTop::operator<(const ClauTop &altra) const {
    // Més places primer (ordre descendent)
    if (a_places != altra.a_places)
        return a_places > altra.a_places;

    // En cas d'empat, més estances primer (ordre descendent)
    if (a_estances != altra.a_estances)
        return a_estances > altra.a_estances;

    // Si tornen a empatar, l'índex més petit primer (ordre ascendent)
    return a_index < altra.a_index;
}


