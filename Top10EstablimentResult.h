// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#ifndef TOP10ESTABLIMENTRESULT_H
#define TOP10ESTABLIMENTRESULT_H

#include <string>
#include <vector>

using namespace std;

/// Un element del resultat de l'opció (g): un dels establiments amb més places d'una comarca.
class Top10EstablimentResult {
public:
    Top10EstablimentResult(const string &nom, int places, int estances);
    // pre: cert
    // post: resultat amb el nom de l'establiment i les seves places i estances

    string nom() const;
    // pre: cert
    // post: retorna el nom (rètol) de l'establiment

    int places() const;
    // pre: cert
    // post: retorna el total de places de l'establiment

    int estances() const;
    // pre: cert
    // post: retorna el total d'estances de l'establiment

private:
    string a_nom;
    int a_places;
    int a_estances;
};

/// Resultat de l'opció (g): els (com a màxim) deu establiments d'una comarca amb més places.
typedef vector<Top10EstablimentResult> top10EstablimentsResults;

#endif // TOP10ESTABLIMENTRESULT_H
