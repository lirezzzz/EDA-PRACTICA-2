// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef MUNICIPI_H
#define MUNICIPI_H

#include <string>
#include <vector>

using namespace std;

/// Un municipi amb els índexs dels seus establiments (dins el vector global d'Establiments), en l'ordre del fitxer CSV.
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

private:
    string a_codi;                    // Codi Municipi (IDESCAT)
    string a_nom;                     // Municipi
    vector<size_t> a_indexs;      // índexs dels establiments, en ordre del fitxer
};

#endif // MUNICIPI_H
