/** @file ClauTop.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef CLAUTOP_H
#define CLAUTOP_H

#include <cstddef>
#include <string>

using namespace std;

/// Clau d'un establiment dins el top 10 d'una comarca.
/// Guarda les places, les estances, l'ordre d'arribada i el nom.
class ClauTop {
public:
    /** @pre cert
        @post clau amb les places, estances i nom de l'establiment i el seu ordre d'arribada dins la comarca
    */
    ClauTop(int places, int estances, size_t ordre, const string &nom);

    /** @pre cert
        @post retorna les places de l'establiment
    */
    int places() const;

    /** @pre cert
        @post retorna les estances de l'establiment
    */
    int estances() const;

    /** @pre cert
        @post retorna el nom (rètol) de l'establiment
    */
    string nom() const;

    /** @pre cert
        @post diu si aquesta clau va abans que altra al top: més places primer, en cas d'empat més
             estances i, si tornen a empatar, l'ordre més petit (l'establiment que surt abans al fitxer)
    */
    bool operator<(const ClauTop &altra) const;

private:
    int a_places;
    int a_estances;
    size_t a_ordre;
    string a_nom;
};

#endif // CLAUTOP_H
