/** @file Municipi.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <vector>
#include <list>
#include <utility>
#include <map>
#include "Establiment.h"
#include "Comptadors.h"
#include "CarrerResult.h"

using namespace std;

/// Un municipi amb els seus establiments (en l'ordre del fitxer CSV) i els comptadors de cada carrer.
class Municipi {
public:
    /** @pre nom és el nom del poble
        @post municipi amb el nom indicat i sense establiments
    */
    Municipi(const string &nom);

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

    /** @pre cert
        @post retorna el total de places i el total d'estances dels establiments del municipi
    */
    pair<int, int> totals() const;

    /** @pre places i nEstabliments tenen una posició per cada unitat d'allotjament
        @post a cada unitat, s'hi han sumat les places dels establiments del municipi que són d'aquesta unitat
             i s'hi ha comptat un establiment més per cada un
    */
    void sumarUnitats(vector<int> &places, vector<size_t> &nEstabliments) const;

    /** @pre places i nEstabliments tenen una posició per cada titular
        @post a cada titular, s'hi han sumat les places dels establiments del municipi que són seus
             i s'hi ha comptat un establiment més per cada un
    */
    void sumarTitulars(vector<int> &places, vector<size_t> &nEstabliments) const;

private:
    string a_nom;                     ///< Municipi
    list<Establiment> a_establiments;   ///< els establiments del municipi, en ordre del fitxer
    map<string, Comptadors> a_carrers; ///< nom del carrer -> comptadors
    string a_millorCarrer;            ///< carrer amb més establiments (en empat, el primer per ordre alfabètic)
    size_t a_nMillorCarrer;           ///< nombre d'establiments d'aquest carrer
};

#endif // MUNICIPI_H
