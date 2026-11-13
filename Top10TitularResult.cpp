/** @file Top10TitularResult.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "Top10TitularResult.h"

Top10TitularResult::Top10TitularResult(const string &cif, const string &raoSocial, int places, size_t nEstabliments)
    : a_cif(cif), a_raoSocial(raoSocial), a_places(places), a_nEstabliments(nEstabliments) {}

string Top10TitularResult::cif() const {
    return a_cif;
}

string Top10TitularResult::raoSocial() const {
    return a_raoSocial;
}

int Top10TitularResult::places() const {
    return a_places;
}

size_t Top10TitularResult::nEstabliments() const {
    return a_nEstabliments;
}
