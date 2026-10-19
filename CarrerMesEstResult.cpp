// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#include "CarrerMesEstResult.h"

CarrerMesEstResult::CarrerMesEstResult(const string &comarca, const string &municipi,
                                       const string &carrer, size_t nEstabliments)
    : a_comarca(comarca), a_municipi(municipi), a_carrer(carrer), a_nEstabliments(nEstabliments) {}

string CarrerMesEstResult::comarca() const {
    return a_comarca;
}

string CarrerMesEstResult::municipi() const {
    return a_municipi;
}

string CarrerMesEstResult::carrer() const {
    return a_carrer;
}

size_t CarrerMesEstResult::nEstabliments() const {
    return a_nEstabliments;
}
