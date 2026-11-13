/** @file Establiment.h
    @author Diego Cortés, usuari u6112490

    Practica 1
*/

#ifndef ESTABLIMENT_H
#define ESTABLIMENT_H

#include <string>

using namespace std;

/// Un establiment turístic (una fila del fitxer CSV).
/// Només guardem els camps que necessitem: els de l'opció 03 i, de la unitat d'allotjament i del titular,
/// el número de la seva fila a les taules d'Establiments (així no es repeteix el text a cada establiment).
class Establiment {
public:
    /** @pre places >= 0, estances >= 0
        @post establiment amb les dades indicades; unitat i titular són els números de fila de la seva unitat
             d'allotjament i del seu titular
    */
    Establiment(const string &nom, const string &carrer, const string &numero,
                const string &numInscripcio, int places, int estances, int unitat, int titular);

    /** @pre cert
        @post retorna el rètol (nom) de l'establiment
    */
    string nom() const;

    /** @pre cert
        @post retorna el nom de la via (carrer)
    */
    string carrer() const;

    /** @pre cert
        @post retorna el número de la via
    */
    string numero() const;

    /** @pre cert
        @post retorna el número d'inscripció
    */
    string numInscripcio() const;

    /** @pre cert
        @post retorna el total de places
    */
    int places() const;

    /** @pre cert
        @post retorna el total d'estances
    */
    int estances() const;

    /** @pre cert
        @post retorna el número de fila de la unitat d'allotjament de l'establiment
    */
    int unitat() const;

    /** @pre cert
        @post retorna el número de fila del titular de l'establiment
    */
    int titular() const;

private:
    string a_nom;           ///< Rètol
    string a_carrer;        ///< Nom de la via
    string a_numero;        ///< Número
    string a_numInscripcio; ///< Número inscripció
    int a_places;           ///< Total places
    int a_estances;         ///< Total estances
    int a_unitat;           ///< Número de fila de la unitat d'allotjament
    int a_titular;          ///< Número de fila del titular
};

#endif // ESTABLIMENT_H
