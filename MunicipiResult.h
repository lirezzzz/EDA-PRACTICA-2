/** @file MunicipiResult.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef MUNICIPIRESULT_H
#define MUNICIPIRESULT_H

#include <string>

using namespace std;

/// Resultat de l'opció 02: un municipi i el seu nombre d'establiments.
class MunicipiResult {
public:
    /** @pre cert
        @post resultat amb el nom del municipi i el seu nombre d'establiments
    */
    MunicipiResult(const string &nom, size_t nEstabliments);

    /** @pre cert
        @post retorna el nom del municipi
    */
    string nom() const;

    /** @pre cert
        @post retorna el nombre d'establiments del municipi
    */
    size_t nEstabliments() const;

private:
    string a_nom;
    size_t a_nEstabliments;
};

#endif // MUNICIPIRESULT_H
