// Diego Cortés
// Usuari u6112490
// Practica 1

#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include "Establiment.h"
#include "Comptadors.h"
#include "CarrerResult.h"

using namespace std;

/// Un municipi amb els seus establiments (en l'ordre del fitxer CSV) i els comptadors de cada carrer.
class Municipi {
public:
    /** @pre cert
        @post municipi buit, sense cap establiment
    */
    Municipi();

    /** @pre codi és el codi idescat del municipi i nom, el nom del poble
        @post municipi amb el codi i nom indicats i sense establiments
    */
    Municipi(const string &codi, const string &nom);

    /** @pre cert
        @post retorna el codi idescat del municipi
    */
    string codi() const;

    /** @pre cert
        @post retorna el nom del municipi
    */
    string nom() const;

    /** @pre cert
        @post retorna el numero d'establiments del municipi
    */
    size_t nEstabliments() const;

    /** @pre cert
        @post e s'ha afegit al final dels establiments del municipi i s'ha comptat als comptadors del seu carrer
             (si el carrer no existia, s'ha creat amb aquest únic establiment)
    */
    void afegirEstabliment(const Establiment &e);

    /** @pre cert
        @post retorna els establiments del municipi en l'ordre del fitxer
    */
    list<Establiment> establiments() const;

    /** @pre cert
        @post retorna els comptadors del carrer d'aquest municipi; tot a 0 si el carrer no hi és
    */
    CarrerResult comptadorsDeCarrer(const string &carrer) const;

    /** @pre cert
        @post retorna el carrer del municipi amb més establiments (amb els seus comptadors); en cas d'empat,
             el primer per ordre alfabètic. Tot a 0 i carrer buit si el municipi no té cap establiment
    */
    CarrerResult carrerMesEstabliments() const;

private:
    string a_codi;                    ///< Codi Municipi (IDESCAT)
    string a_nom;                     ///< Municipi
    vector<Establiment> a_establiments; ///< els establiments del municipi, en ordre del fitxer
    map<string, Comptadors> a_carrers; ///< nom del carrer -> comptadors
};

#endif // MUNICIPI_H
