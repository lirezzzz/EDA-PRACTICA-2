/** @file Top10TitularResult.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef TOP10TITULARRESULT_H
#define TOP10TITULARRESULT_H

#include <string>
#include <vector>

using namespace std;

/// Un element del resultat de l'opció (j): un dels titulars amb més places.
class Top10TitularResult {
public:
    /** @pre cert
        @post resultat amb el CIF, la raó social, les places i el nombre d'establiments del titular
    */
    Top10TitularResult(const string &cif, const string &raoSocial, int places, size_t nEstabliments);

    /** @pre cert
        @post retorna el CIF del titular
    */
    string cif() const;

    /** @pre cert
        @post retorna la raó social del titular
    */
    string raoSocial() const;

    /** @pre cert
        @post retorna el total de places dels establiments del titular
    */
    int places() const;

    /** @pre cert
        @post retorna el nombre d'establiments del titular
    */
    size_t nEstabliments() const;

private:
    string a_cif;
    string a_raoSocial;
    int a_places;
    size_t a_nEstabliments;
};

/// Resultat de l'opció (j): els (com a màxim) deu titulars amb més places.
typedef vector<Top10TitularResult> top10TitularsResults;

#endif // TOP10TITULARRESULT_H
