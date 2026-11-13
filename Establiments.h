/** @file Establiments.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef ESTABLIMENTS_H
#define ESTABLIMENTS_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include "Comarca.h"
#include "MunicipiResult.h"
#include "MaximMunicipiResult.h"
#include "CarrerResult.h"
#include "CarrerMesEstResult.h"
#include "Top10EstablimentResult.h"
#include "Top10TitularResult.h"

using namespace std;

/// Resultat de l'opció 05: per cada comarca, el municipi amb més establiments.
typedef vector<MaximMunicipiResult> MaximMunicipiResults;

class Establiments {
public:
    /** @pre path és el camí d'un fitxer CSV amb una línia de capçalera, separador ',' i camps entre cometes
        @post s'han eliminat les dades carregades prèviament i aquest Establiments conté els establiments
             del fitxer agrupats per comarca i municipi; retorna el nombre de files de dades llegides
             (0 si el fitxer no s'ha pogut obrir)
    */
    size_t llegirDades(const string &path);

    /** @pre cert
        @post retorna els municipis de la comarca codiComarca amb el seu nombre d'establiments,
             ordenats pel nom del municipi ascendentment; buit si la comarca no existeix
    */
    vector<MunicipiResult> municipisPerComarca(int codiComarca) const;

    /** @pre cert
        @post retorna els establiments del municipi amb codi IDESCAT codiMunicipi en l'ordre del fitxer;
             buida si el municipi no existeix
    */
    list<Establiment> establimentsPerMunicipi(const string &codiMunicipi) const;

    /** @pre cert
        @post retorna el nombre d'establiments, de places i d'estances del carrer nomCarrer del municipi
             codiMunicipi; tot a 0 si el municipi o el carrer no existeixen
    */
    CarrerResult comptadorsDeCarrer(const string &codiMunicipi, const string &nomCarrer) const;

    /** @pre cert
        @post retorna, per cada comarca amb dades, el municipi amb més establiments (en cas d'empat dins
             la comarca, el que hi ha arribat primer en l'ordre del fitxer), ordenats pel nombre
             d'establiments descendentment i, en cas d'empat, pel nom del municipi ascendentment
    */
    MaximMunicipiResults maximMunicipi() const;

    /** @pre cert
        @post retorna, per cada comarca amb dades, el carrer (amb el seu municipi) amb més establiments,
             ordenats pel nombre d'establiments descendentment i, en cas d'empat, pel nom del carrer ascendentment
    */
    CarrerMesEstResults carrerMesEstablimentsPerComarca() const;

    /** @pre cert
        @post retorna els (com a màxim) deu establiments de la comarca codiComarca amb més places (en cas
             d'empat, més estances); buit si la comarca no existeix
    */
    top10EstablimentsResults top10Establiments(int codiComarca) const;

    /** @pre cert
        @post retorna el total de places i el total d'estances del municipi amb codi IDESCAT codiMunicipi;
             (0, 0) si el municipi no existeix
    */
    pair<int, int> totalsMunicipi(const string &codiMunicipi) const;

    /** @pre cert
        @post retorna el carrer del municipi codiMunicipi amb més establiments, amb els seus comptadors (en cas
             d'empat, el primer per ordre alfabètic); carrer buit i tot a 0 si el municipi no existeix
    */
    CarrerResult carrerMesEstablimentsDelMunicipi(const string &codiMunicipi) const;

    /** @pre cert
        @post retorna els (com a màxim) deu titulars (agrupats pel CIF) amb més places; en cas d'empat, els que tenen
             més establiments i, si encara empaten, per CIF ascendentment. De cada titular es dóna la raó social que va
             primer per ordre alfabètic, sense comptar les buides
    */
    top10TitularsResults top10Titulars() const;

    /** @pre cert
        @post retorna, per cada unitat d'allotjament de la comarca codiComarca, el total de places dels seus
             establiments, ordenades pel nom de la unitat; buit si la comarca no existeix
    */
    map<string, int> placesUnitat(int codiComarca) const;

private:
    vector<Comarca> a_comarques; ///< cada comarca conté els seus municipis
    vector<string> a_unitats;    ///< les unitats d'allotjament, per número de fila
    vector<pair<string, string> > a_titulars; ///< els titulars (CIF i raó social), per número de fila
    /// per cada codi de municipi, el codi de la seva comarca. Serveix per saber a quina comarca anar a buscar;
    /// després, dins de la comarca, el seu propi índex troba el municipi
    map<string, int> a_indexMunicipis;
};

#endif // ESTABLIMENTS_H
