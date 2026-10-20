// Diego Cortés i Oriol Sala
// Usuari u6112490, u6112518
// Exercici 1

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Establiments.h"

using namespace std;

void mostrarTitol(const string &titol) {
    // pre: cert
    // post: s'ha mostrat per cout el títol emmarcat amb asteriscs
    string linia(titol.length() + 4, '*');
    cout << linia << endl;
    cout << "* " << titol << " *" << endl;
    cout << linia << endl;
}

void mostrarMenu() {
    cerr << endl;
    cerr << "01: Llegir dades" << endl;
    cerr << "02: Codi comarca -> municipis" << endl;
    cerr << "03: Codi municipi -> establiments" << endl;
    cerr << "04: Comptadors de carrer" << endl;              // (d)
    cerr << "05: Municipi amb mes establiments" << endl;
    cerr << "06: Carrer amb mes establiments" << endl;       // (f)
    cerr << "07: Top 10 establiments per comarca" << endl;   // (g)
    cerr << "08: Totals municipi" << endl;                   // (h)
    cerr << "09: Carrer mes establiments del municipi" << endl; // (i)
    cerr << "10: Top 10 titulars" << endl;                   // (j)
    cerr << "11: Places unitat" << endl;                     // (k)
    cerr << "0: Acabar" << endl;
    cerr << "Opcio: ";
}


void opcioLlegirDades(Establiments &establiments) {
    // pre: cert
    // post: llegeix el path del fitxer CSV, el carrega a establiments i mostra el nombre de línies llegides
    string path;
    cin >> path;
    size_t n = establiments.llegirDades(path);
    mostrarTitol("01: Llegir dades");
    cout << "Numero de linies: " << n << endl;
}

void opcioMunicipisPerComarca(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de comarca i mostra els seus municipis amb el nombre d'establiments
    int codi;
    cin >> codi;
    mostrarTitol("02: Codi comarca -> municipis");
    cout << "Codi de comarca: " << codi << endl;
    for (const MunicipiResult &m : establiments.municipisPerComarca(codi))
        cout << m.nom() << " => " << m.nEstabliments() << endl;
}

string formatNumero(const string &numero) {
    // pre: cert
    // post: retorna numero; si comença per dígit, s'omple amb zeros a l'esquerra fins a 5 caràcters
    if (numero.empty() || !isdigit((unsigned char)numero[0]) || numero.length() >= 5)
        return numero;
    return string(5 - numero.length(), '0') + numero;
}

void opcioEstablimentsPerMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de municipi i mostra els seus establiments
    string codi;
    cin >> codi;
    mostrarTitol("03: Codi municipi -> establiments");
    cout << "Codi de municipi: " << codi << endl;
    for (const Establiment &e : establiments.establimentsPerMunicipi(codi))
        cout << e.nom() << " | " << e.carrer() << " | num: " << formatNumero(e.numero())
             << " | Número inscripció: " << e.numInscripcio()
             << " | places: " << e.places() << " | estances: " << e.estances() << endl;
}

void opcioMaximMunicipi(const Establiments &establiments) {
    // pre: cert
    // post: mostra, per cada comarca, el municipi amb més establiments
    MaximMunicipiResults resultat = establiments.maximMunicipi();
    mostrarTitol("04: Municipi amb mes establiments");
    for (size_t i = 0; i < resultat.size(); i++)
        cout << resultat[i].comarca() << " | " << resultat[i].municipi() << " => "
             << resultat[i].nEstabliments() << endl;
}

// ===== ZONA PERSONA A: opcions (d) i (f) =====

void opcioComptadorsDeCarrer(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de municipi i el nom d'un carrer i mostra els seus comptadors
    // TODO (persona A): els noms de carrer tenen espais: llegir-lo amb getline (compte amb el salt de línia pendent)
}

void opcioCarrerMesEstabliments(const Establiments &establiments) {
    // pre: cert
    // post: mostra, per cada comarca, el carrer amb més establiments
    // TODO (persona A)
}

// ===== FI ZONA PERSONA A =====

// ===== ZONA PERSONA B: opció (g) =====

void opcioTop10Establiments(const Establiments &establiments) {
    // pre: cert
    // post: llegeix un codi de comarca i mostra els deu establiments amb més places

    int codi;
    cin >> codi;

    mostrarTitol("07: Top 10 establiments per comarca");
    cout << "Codi de comarca: " << codi << endl;

    top10EstablimentsResults r = establiments.top10Establiments(codi);

    for (const Top10EstablimentsResult &e : r) {
        cout << e.retol << " | "
             << e.nomVia << " | num: " << e.numero
             << " | places: " << e.places
             << " | estances: " << e.estances
             << endl;
    }
}

// ===== FI ZONA PERSONA B =====


int main() {
    Establiments establiments;
    int opcio;

    mostrarMenu();
    cin >> opcio;

    while (opcio != 0) {

        if (opcio == 1) opcioLlegirDades(establiments);
        else if (opcio == 2) opcioMunicipisPerComarca(establiments);
        else if (opcio == 3) opcioEstablimentsPerMunicipi(establiments);
        else if (opcio == 4) opcioComptadorsDeCarrer(establiments);          // (d)
        else if (opcio == 5) opcioMaximMunicipi(establiments);
        else if (opcio == 6) opcioCarrerMesEstabliments(establiments);       // (f)
        else if (opcio == 7) opcioTop10Establiments(establiments);           // (g)
        else if (opcio == 8) opcioTotalsMunicipi(establiments);              // (h)
        else if (opcio == 9) opcioCarrerMesEstabMunicipi(establiments);      // (i)
        else if (opcio == 10) opcioTop10Titulars(establiments);              // (j)
        else if (opcio == 11) opcioPlacesUnitat(establiments);               // (k)
        else cerr << "Opcio incorrecta" << endl;

        mostrarMenu();
        cin >> opcio;
    }

    return 0;
}

