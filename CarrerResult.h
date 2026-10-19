// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#ifndef CARRERRESULT_H
#define CARRERRESULT_H

#include <string>

using namespace std;

/// Comptadors d'un carrer: resultat de l'opció (d) comptadorsDeCarrer.
class CarrerResult {
public:
    CarrerResult(const string &carrer, size_t nEstabliments, int places, int estances);
    // pre: cert
    // post: resultat amb el nom del carrer i el seu nombre d'establiments, de places i d'estances

    string carrer() const;
    // pre: cert
    // post: retorna el nom del carrer

    size_t nEstabliments() const;
    // pre: cert
    // post: retorna el nombre d'establiments del carrer

    int places() const;
    // pre: cert
    // post: retorna el total de places del carrer

    int estances() const;
    // pre: cert
    // post: retorna el total d'estances del carrer

private:
    string a_carrer;
    size_t a_nEstabliments;
    int a_places;
    int a_estances;
};

#endif // CARRERRESULT_H
