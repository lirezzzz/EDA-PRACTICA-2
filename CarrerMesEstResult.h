/** @file CarrerMesEstResult.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef CARRERMESESTRESULT_H
#define CARRERMESESTRESULT_H

#include <string>
#include <vector>

using namespace std;

/// Un element del resultat de l'opció (f): el carrer amb més establiments d'una comarca.
class CarrerMesEstResult {
public:
    /** @pre cert
        @post resultat amb el nom de la comarca, el del municipi, el del carrer i el seu nombre d'establiments
    */
    CarrerMesEstResult(const string &comarca, const string &municipi, const string &carrer, size_t nEstabliments);

    /** @pre cert
        @post retorna el nom de la comarca
    */
    string comarca() const;

    /** @pre cert
        @post retorna el nom del municipi on és el carrer
    */
    string municipi() const;

    /** @pre cert
        @post retorna el nom del carrer
    */
    string carrer() const;

    /** @pre cert
        @post retorna el nombre d'establiments del carrer
    */
    size_t nEstabliments() const;

private:
    string a_comarca;
    string a_municipi;
    string a_carrer;
    size_t a_nEstabliments;
};

/// Resultat de l'opció (f): per cada comarca, el carrer amb més establiments.
typedef vector<CarrerMesEstResult> CarrerMesEstResults;

#endif // CARRERMESESTRESULT_H
