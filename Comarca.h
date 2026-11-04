// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#ifndef COMARCA_H
#define COMARCA_H

#include <string>
#include <vector>
#include <list>
#include "Municipi.h"
#include "Establiment.h"
#include "CarrerMesEstResult.h"
#include "ClauTop.h"
#include "Top10EstablimentResult.h"

using namespace std;

/// Una comarca amb els seus municipis (cada un guarda els seus establiments) i el top 10 d'establiments.
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

    void afegirEstabliment(const string &codiMunicipi, const string &nomMunicipi,
                           const Establiment &e);
    // pre: el municipi codiMunicipi pertany a aquesta comarca
    // post: e s'ha afegit al final dels establiments del municipi codiMunicip. si el municipi no existia, s'ha creat amb el nom nomMunicipi.
    //       si ara aquest municipi té estrictament més establiments que el màxim anterior, passa a ser el municipi màxim
    
    list<Establiment> establimentsDeMunicipi(const string &codiMunicipi) const;
    // pre: cert
    // post: retorna els establiments del municipi codiMunicipi en l'ordre del fitxer; buida si no hi és

    top10EstablimentsResults top10() const;
    // pre: cert
    // post: retorna els (com a màxim) deu establiments d'aquesta comarca amb més places (en cas d'empat,
    //       més estances), ordenats del millor al pitjor

    CarrerMesEstResult carrerMesEstabliments() const;
    // pre: aquesta Comarca no és buida
    // post: retorna el carrer amb més establiments de la comarca, amb el nom de la comarca i del municipi on és;
    //       en cas d'empat, el del municipi de codi més petit i, dins d'ell, el primer per ordre alfabètic

    const Municipi &municipiMaxim() const;
    // pre: aquesta Comarca no és buida
    // post: retorna el municipi amb més establiments; en cas d'empat, el que hi ha arribat primer en l'ordre del fitxer

private:
    void actualitzarTop(const Establiment &e);
    // pre: e és el darrer establiment afegit a la comarca
    // post: e s'ha tingut en compte per al top 10: si està entre els deu millors, és dins a_top
    //       i a_top no té mai més de deu claus

    int a_codi;                  // Codi Comarca (IDESCAT)
    string a_nom;                // Comarca
    vector<Municipi> a_municipis;
    size_t a_nEstabliments;      // establiments de la comarca llegits fins ara (dóna l'ordre d'arribada)
    string a_codiMaxim;          // codi del municipi amb més establiments
    size_t a_nMaxim;             // nombre d'establiments d'aquest municipi
    vector<ClauTop> a_top;       // els deu millors establiments, ordenats del millor al pitjor
};

#endif // COMARCA_H
