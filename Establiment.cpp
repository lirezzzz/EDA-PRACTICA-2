/** @file Establiment.cpp
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#include "Establiment.h"

Establiment::Establiment() : a_places(0), a_estances(0), a_unitat(0), a_titular(0) {}

Establiment::Establiment(const string &nom, const string &carrer, const string &numero,
                         const string &numInscripcio, int places, int estances, int unitat, int titular)
    : a_nom(nom), a_carrer(carrer), a_numero(numero),
      a_numInscripcio(numInscripcio), a_places(places), a_estances(estances),
      a_unitat(unitat), a_titular(titular) {}

string Establiment::nom() const {
    return a_nom;
}

string Establiment::carrer() const {
    return a_carrer;
}

string Establiment::numero() const {
    return a_numero;
}

string Establiment::numInscripcio() const {
    return a_numInscripcio;
}

int Establiment::places() const {
    return a_places;
}

int Establiment::estances() const {
    return a_estances;
}

int Establiment::unitat() const {
    return a_unitat;
}

int Establiment::titular() const {
    return a_titular;
}
