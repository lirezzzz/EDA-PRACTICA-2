// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 2

#ifndef CLAUTOP_H
#define CLAUTOP_H

#include <cstddef>

using namespace std;

/// Clau d'un establiment dins el top 10 d'una comarca (peça interna).
/// Guarda només tres números: el set del top no copia cap establiment.
class ClauTop {
public:
    ClauTop(int places, int estances, size_t index);
    // pre: cert
    // post: clau amb les places i estances de l'establiment i el seu índex dins la comarca

    int places() const;
    // pre: cert
    // post: retorna les places de l'establiment

    int estances() const;
    // pre: cert
    // post: retorna les estances de l'establiment

    size_t index() const;
    // pre: cert
    // post: retorna la posició de l'establiment dins els establiments de la comarca

    bool operator<(const ClauTop &altra) const;
    // pre: cert
    // post: diu si aquesta clau va abans que altra al top: més places primer, en cas d'empat més
    //       estances i, si tornen a empatar, l'índex més petit (l'establiment que surt abans al fitxer).
    //       Ha de ser un ordre total estricte: si dues claus diferents es consideren iguals, el set
    //       en descarta una.

private:
    int a_places;
    int a_estances;
    size_t a_index;
};

#endif // CLAUTOP_H
