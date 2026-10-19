// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#ifndef COMARCA_H
#define COMARCA_H

#include <string>
#include <vector>
#include <list>
#include <set>
#include "Municipi.h"
#include "Establiment.h"
#include "ClauTop.h"
#include "Top10EstablimentResult.h"

using namespace std;

/// Una comarca amb un vector on estan els seus municipis.
class Comarca {
public:
    Comarca();
    // pre: cert
    // post: comarca buida (codi 0, sense nom ni cap municipi)

    Comarca(int codi, const string &nom);
    // pre: codi és el codi idescat de la comarca
    // post: comarca amb el codi i nom indicats i sense municipis

    int codi() const;
    // pre: cert
    // post: retorna el codi idescat de la comarca

    string nom() const;
    // pre: cert
    // post: retorna el nom de la comarca

    bool buida() const;
    // pre: cert
    // post: retorna cert si la comarca no té cap municipi

    const vector<Municipi> &municipis() const;
    // pre: cert
    // post: retorna els municipis de la comarca

    int cercaDicotomica(const string &codiMunicipi) const;
    // pre: els municipis estan ordenats per codi idescat (ordre de string de menor a major basicament 0<3 en format string)
    // post: retorna la posició de codiMunicipi dins els municipis, o -1 si no hi és

    int cercaDicotomica(const string &codiMunicipi, int &pos) const;
    // pre: els municipis estan ordenats per codi idescat
    // post: com la cerca d'un parametre, i pos és la posició de codiMunicipi o, si no hi és, on s'hauria d'inserir per mantenir l'ordre

    bool existeixMunicipi(const string &codiMunicipi) const;
    // pre: els municipis estan ordenats per codi idescat (ordre de string, que funciona com hem especificat abans a la cerca dicotomica)
    // post: retorna cert si la comarca té un municipi amb codi codiMunicipi

    void afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                           const Establiment &e);
    // pre: el municipi codiMunicipi pertany a aquesta comarca
    // post: e s'ha afegit al final dels establiments del municipi codiMunicip. si el municipi no existia, s'ha creat amb el nom nomMunicipi.
    //       si ara aquest municipi té estrictament més establiments que el màxim anterior, passa a ser el municipi màxim
    
    list<Establiment> establimentsDeMunicipi(const string &codiMunicipi) const;
    // pre: cert
    // post: retorna els establiments del municipi codiMunicipi en l'ordre del fitxer; buida si no hi és

    // ===== ZONA PERSONA B: opció (g) =====
    top10EstablimentsResults top10() const;
    // pre: cert
    // post: retorna els (com a màxim) deu establiments d'aquesta comarca amb més places (en cas d'empat,
    //       més estances), ordenats del millor al pitjor
    // ===== FI ZONA PERSONA B =====

    const Municipi &municipiMaxim() const;
    // pre: aquesta Comarca no és buida
    // post: retorna el municipi amb més establiments; en cas d'empat, el que hi ha arribat primer en l'ordre del fitxer

private:
    void actualitzarTop(size_t index, const Establiment &e);
    // pre: index és la posició d'e dins a_establiments
    // post: e s'ha tingut en compte per al top 10: si està entre els deu millors, és dins a_top
    //       i a_top no té mai més de deu claus (zona persona B)

    int a_codi;                  // Codi Comarca (IDESCAT)
    string a_nom;                // Comarca
    vector<Municipi> a_municipis;
    vector<Establiment> a_establiments;
    string a_codiMaxim;          // codi del municipi amb més establiments
    size_t a_nMaxim;             // nombre d'establiments d'aquest municipi
    set<ClauTop> a_top;          // els deu millors establiments, per places (zona persona B)
};

#endif // COMARCA_H
