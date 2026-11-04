// Diego Cortés
// Usuari u6112490
// Practica 1

#ifndef CARRERRESULT_H
#define CARRERRESULT_H

#include <string>

using namespace std;

/// Comptadors d'un carrer: resultat de l'opció (d) comptadorsDeCarrer.
class CarrerResult {
public:
    /** @pre cert
        @post resultat amb el nom del carrer i el seu nombre d'establiments, de places i d'estances
    */
    CarrerResult(const string &carrer, size_t nEstabliments, int places, int estances);

    /** @pre cert
        @post retorna el nom del carrer
    */
    string carrer() const;

    /** @pre cert
        @post retorna el nombre d'establiments del carrer
    */
    size_t nEstabliments() const;

    /** @pre cert
        @post retorna el total de places del carrer
    */
    int places() const;

    /** @pre cert
        @post retorna el total d'estances del carrer
    */
    int estances() const;

private:
    string a_carrer;
    size_t a_nEstabliments;
    int a_places;
    int a_estances;
};

#endif // CARRERRESULT_H
