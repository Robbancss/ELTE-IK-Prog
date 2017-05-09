//Készítette:    Pánczél Róbert
//Dátum:         2017.04.15.
//NEPTUN kód:    EY2P3W
//Mail:          robi.panczel@gmail.com
//Csoport:       06. csoport
//Feladat:       Melyik az a telepules, ahol a legtobb madarfaj fordult elo?

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "naplo.h"
#include "read.h"

using namespace std;

//Feladat: 	A fõprogram gondoskodik a beolvasás, a kiértékelés, kiíratás részek aktivizálásáról.
//Bemenõ adatok:vector<vector<int> > naplo 	    - méréseket tartalmazó mátrix
//		        vector<string> telepules 		- települések neveit tartalmazó tömb
//		        vector<string> faj          	- fajok neveit tartalmazó tömb
//Kimenõ adatok:
//Tevékenység:	Eldönti, hogy mi legyen a beolvasás forrása:
//    parancssorban megadott szöveges állomány neve (ez az alapértelmezett, ha megadtuk)
//    vagy menübõl választhatunk a billentyûzet illetve szöveges állomány között.
//    Feltölti a bemenõ változókat: billentyûzetrõl beolvassa a települések számát,
//    majd a neveiket, ugyanazt teszi a fajokkal.
//    Ezután meghívja a feladatot megoldó mindenkinek_ket_otos() függvényt.
//    Ennek eredményétõl függõen pozitív vagy negatív választ ír a standard kimenetre.
int main(int argc, char *argv[])
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    // Beolvasás
    int s = 0;
    string fajlnev;
    if (argc<=1) {
        cout << "Valassza ki az adatbevitel modjat!\n";
        cout << "1 - adatok beolvasasa fajlbol\n";
        cout << "2 - adatok beolvasasa billentyuzetrol\n";
        cout << "3 - kilepes\n";
        s = read_int("Adatbevitel modja: ", "1, 2 vagy 3 lehet", egykettoharom);
    }
    switch (s) {
        case 0:
            if(argc>1) {
            fajlnev = argv[1];
            fajlbol_olvas(fajlnev, telepules, faj, naplo);
            }
            else exit(0);
            break;

        case 1:
            cout << "Add meg a fajl nevet: ";
            cin >> fajlnev;
            fajlbol_olvas(fajlnev, telepules, faj, naplo);
            break;

        case 2:
            n = read_int("Hany telepules van? ", "Termeszetes szamot kerek!", nat);
            cout << "Adja meg a telepulesek neveit:" << endl;
            neveket_olvas(n, "telepules", telepules);
            cout << endl;

            m = read_int("Hany faj van? ","Termeszetes szamot kerek!", nat);
            cout << "Adja meg a fajokat:"<< endl;
            neveket_olvas(m, "faj", faj);
            cout << endl;

            cout << "Adja meg az mereseket!"<< endl;
            madarakat_olvas(telepules, faj, naplo);
            cout << endl;
            break;

        default:
            exit(0);
    }

    // Kiértékelés
    int index = legtobb_madarfajos_telepules(naplo);
    cout << "A legtobb madar itt fordul elo:" << telepules[index] << endl;

    cout<<endl;
    return 0;
}
