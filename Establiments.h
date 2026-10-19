// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef ESTABLIMENTS_H
#define ESTABLIMENTS_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include "Comarca.h"
#include "MunicipiResult.h"
#include "MaximMunicipiResult.h"
#include "CarrerResult.h"
#include "CarrerMesEstResult.h"
#include "Top10EstablimentResult.h"

using namespace std;

/// Resultat de l'opció 04: per cada comarca, el municipi amb més establiments.
typedef vector<MaximMunicipiResult> MaximMunicipiResults;

class Establiments {
public:
    size_t llegirDades(const string &path);
    // pre: path és el camí d'un fitxer CSV amb una línia de capçalera, separador ',' i camps entre cometes
    // post: s'han eliminat les dades carregades prèviament i aquest Establiments conté els establiments
    //       del fitxer agrupats per comarca i municipi; retorna el nombre de files de dades llegides
    //       (0 si el fitxer no s'ha pogut obrir)

    vector<MunicipiResult> municipisPerComarca(int codiComarca) const;
    // pre: cert
    // post: retorna els municipis de la comarca codiComarca amb el seu nombre d'establiments,
    //       ordenats pel nom del municipi ascendentment; buit si la comarca no existeix

    list<Establiment> establimentsPerMunicipi(const string &codiMunicipi) const;
    // pre: cert
    // post: retorna els establiments del municipi amb codi IDESCAT codiMunicipi en l'ordre del fitxer;
    //       buida si el municipi no existeix

    // ===== ZONA PERSONA A: opció (d) =====
    CarrerResult comptadorsDeCarrer(const string &codiMunicipi, const string &nomCarrer) const;
    // pre: cert
    // post: retorna el nombre d'establiments, de places i d'estances del carrer nomCarrer del municipi
    //       codiMunicipi; tot a 0 si el municipi o el carrer no existeixen
    // ===== FI ZONA PERSONA A =====

    MaximMunicipiResults maximMunicipi() const;
    // pre: cert
    // post: retorna, per cada comarca amb dades, el municipi amb més establiments (en cas d'empat dins
    //       la comarca, el que hi ha arribat primer en l'ordre del fitxer), ordenats pel nombre
    //       d'establiments descendentment i, en cas d'empat, pel nom del municipi ascendentment

    // ===== ZONA PERSONA A: opció (f) =====
    CarrerMesEstResults carrerMesEstablimentsPerComarca() const;
    // pre: cert
    // post: retorna, per cada comarca amb dades, el carrer (amb el seu municipi) amb més establiments,
    //       ordenats pel nombre d'establiments descendentment i, en cas d'empat, pel nom del carrer ascendentment
    // ===== FI ZONA PERSONA A =====

    // ===== ZONA PERSONA B: opció (g) =====
    top10EstablimentsResults top10Establiments(int codiComarca) const;
    // pre: cert
    // post: retorna els (com a màxim) deu establiments de la comarca codiComarca amb més places (en cas
    //       d'empat, més estances); buit si la comarca no existeix
    // ===== FI ZONA PERSONA B =====

private:
    vector<Comarca> a_comarques; // cada comarca conté els seus municipis
    map<string, int> a_indexMunicipis;  //codi del municipi i codi de la seva comarca
};

#endif // ESTABLIMENTS_H
