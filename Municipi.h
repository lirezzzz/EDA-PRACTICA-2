// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <vector>
#include <map>
#include "Comptadors.h"
#include "CarrerResult.h"

using namespace std;

/// Un municipi amb els índexs dels seus establiments (dins el vector d'establiments de la seva Comarca), en l'ordre del fitxer CSV.
class Municipi {
public:
    Municipi();
    // pre: cert
    // post: municipi buit, sense cap establiment

    Municipi(const string &codi, const string &nom);
    // pre: codi és el codi idescat del municipi i nom, el nom del poble
    // post: municipi amb el codi i nom indicats i sense establiments

    string codi() const;
    // pre: cert
    // post: retorna el codi idescat del municipi

    string nom() const;
    // pre: cert
    // post: retorna el nom del municipi

    size_t nEstabliments() const;
    // pre: cert
    // post: retorna el numero d'establiments del municipi

    const vector<size_t> &indexs() const;
    // pre: cert
    // post: retorna els índexs dels establiments del municipi en l'ordre del fitxer

    void afegirEstabliment(size_t index);
    // pre: cert
    // post: index s'ha afegit al final dels índexs d'establiments del municipi

    // ===== ZONA PERSONA A: opcions (d) i (f) =====
    void afegirCarrer(const string &carrer, int places, int estances);
    // pre: cert
    // post: als comptadors del carrer s'ha comptat un establiment més amb aquestes places i estances
    //       (si el carrer no existia, s'ha creat amb aquest únic establiment)

    CarrerResult comptadorsDeCarrer(const string &carrer) const;
    // pre: cert
    // post: retorna els comptadors del carrer d'aquest municipi; tot a 0 si el carrer no hi és

    const map<string, Comptadors> &carrers() const;
    // pre: cert
    // post: retorna els comptadors de tots els carrers del municipi, ordenats pel nom del carrer
    // ===== FI ZONA PERSONA A =====

private:
    string a_codi;                    // Codi Municipi (IDESCAT)
    string a_nom;                     // Municipi
    vector<size_t> a_indexs;          // índexs dels establiments, en ordre del fitxer
    map<string, Comptadors> a_carrers; // nom del carrer -> comptadors (zona persona A)
};

#endif // MUNICIPI_H
