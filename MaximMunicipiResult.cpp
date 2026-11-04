/** @file MaximMunicipiResult.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "MaximMunicipiResult.h"

MaximMunicipiResult::MaximMunicipiResult(const string &comarca, const string &municipi, size_t nEstabliments)
    : a_comarca(comarca), a_municipi(municipi), a_nEstabliments(nEstabliments) {}

string MaximMunicipiResult::comarca() const {
    return a_comarca;
}

string MaximMunicipiResult::municipi() const {
    return a_municipi;
}

size_t MaximMunicipiResult::nEstabliments() const {
    return a_nEstabliments;
}
