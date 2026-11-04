/** @file Comptadors.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef COMPTADORS_H
#define COMPTADORS_H

#include <cstddef>

using namespace std;

/// Comptadors d'un carrer dins d'un municipi (peça interna, no es mostra directament).
class Comptadors {
public:
    /** @pre cert
        @post comptadors a zero (cap establiment, cap plaça, cap estança)
    */
    Comptadors();

    /** @pre places >= 0, estances >= 0
        @post s'ha comptat un establiment més amb aquestes places i estances
    */
    void afegir(int places, int estances);

    /** @pre cert
        @post retorna el nombre d'establiments comptats
    */
    size_t nEstabliments() const;

    /** @pre cert
        @post retorna la suma de places dels establiments comptats
    */
    int places() const;

    /** @pre cert
        @post retorna la suma d'estances dels establiments comptats
    */
    int estances() const;

private:
    size_t a_nEstabliments;
    int a_places;
    int a_estances;
};

#endif // COMPTADORS_H
