//Készítette:    Pánczél Róbert
//Dátum:         2017.04.15.
//NEPTUN kód:    EY2P3W
//Mail:          robi.panczel@gmail.com
//Csoport:       06. csoport
//Feladat:       Melyik az a telepules, ahol a legtobb madarfaj fordult elo?

#include "naplo.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "read.h"

using namespace std;

//Feladat: 	Megvizsgálja, hogy hol fordult elo a legtobb madarfaj.
//Bemenő adatok:vector<vector<int> > naplo  - mereseket tartalmazó mátrix
//Kimenő adatok:bool 			            - válasz: visszatérési érték
//Tevékenység:	Maximum kiválasztás: eldönti, hogy a mátrix (meresi napló)
//              minden sorában (telepules) hol van a legtobb madarfaj.
//              Ehhez minden sorra meghívja a Jotanulo() függvényt.
int legtobb_madarfajos_telepules(const vector<vector<int> > &naplo)
{
    int maximum = madarfajDB(naplo[0]);
    int ind = 0;
    for( int i=0; i<(int)naplo.size(); ++i) {
        if (madarfajDB(naplo[i])>=maximum){
            maximum = madarfajDB(naplo[i]);
            ind = i;
        }
    }
    return ind;
}

//Feladat: 	Hány madarfaj van egy telepulesen.
//Bemenő adatok:vector<int> v 	- aktuális telepules madarfaj szama.
//Kimenő adatok:int s		    - madarfajok száma: visszatérési-érték
//Tevékenység:	Megszámolja a madarfajokat.
int madarfajDB(const vector<int> &v)
{
    int s = 0;
    for(int j=0; j<(int)v.size(); ++j) {
        s = s + v[j];
    }
    return s;
}

//Feladat: 	Telepules nevekkel tölt fel egy tömböt.
//Bemenő adatok:int n	         - nevek száma
//		        string msg	     - kiírandó üzenet
//Kimenő adatok:vector<string> v - neveket tartalmazó tömb
//Tevékenység:	Megfelelő méretűre (n) állítja be a tömböt,
//		majd feltölti az értékeit sztringekkel.
void neveket_olvas(int n, const string &msg, vector<string> &v)
{
    v.resize(n);
    for(int i=0; i<n; ++i)
    {
        cout << i+1 << "." << msg << "neve: ";
        cin >> v[i];
    }
}

//Feladat: 	0-nal nagyobb vagy egyenlo számokkal tölt fel egy mátrixot.
//Bemenő adatok:vector<string> telepules 		- telepulesek neveit tartalmazó tömb
//		        vector<string> faj		- madarak neveit tartalmazó tömb
//Kimenő adatok:vector<vector<int> > naplo 	- madarak szamat tartalmazó mátrix
//Tevékenység:	Megfelelő méretűre (telepules.size×faj.size) állítja be a mátrixot,
//		majd feltölti az értékeit 0 vagy annal nagyobb számokkal úgy, hogy rendre jelzi,
//		hogy ezek a számok melyik telepules melyik madarara mert adata.
void madarakat_olvas(const vector<string> &telepules, const vector<string> &faj, vector<vector<int> > &a)
{
    a.resize((int)telepules.size());
    for(int i=0; i<(int)telepules.size(); ++i)
    {
        a[i].resize((int)faj.size());
        cout << telepules[i] << " meresek\n";
        for(int j=0; j<(int)faj.size(); ++j)
        {
            cout << "\t" << faj[j] << ": ";
            a[i][j] = read_int("","0-nel nagyobb vagy egyenlo szamot kerek!", madarszam);
        }
    }
}

//Feladat: 	Telepules és madarfaj neveket olvas egy szöveges állományból,
//          majd ugyanonnan 0 vagy annal nagyobb számokkal feltölti a naplót.
//Bemenő adatok:string fajlnev 		        - inputfájl neve
//Kimenő adatok:vector<string> telepules    - telepulesek neveit tartalmazó tömb
//              vector<string> faj		- madarfajok neveit tartalmazó tömb
//              vector<vector<int> > naplo 	- mereseket tartalmazó mátrix
//Tevékenység:	Megfelelő méretűre (n és m) állítja be a telepules és a madarfajok tömböt,
//		majd feltölti az értékeit sztringekkel. A telepules neve tartalmazhat szóközt is.
//      Megfelelő méretűre (n×m) állítja be a naplo mátrixot,
//		majd feltölti az értékeit 0 vagy annal nagyobb számokkal.
//		A beolvasott adatok a konzolablakban is megjelennek.
void fajlbol_olvas(const string &fajlnev, vector<string> &telepules, vector<string> &faj, vector<vector<int> > &naplo)
{
    ifstream f(fajlnev.c_str());
    if(f.fail()){
        cout << "Hibas fajlnev!\n";
        exit(1);
    }

    int n, m;
    f >> n >> m;
    string str;
    getline(f, str, '\n');

    cout << "\nTelepulesek:\n";
    telepules.resize(n);
    for(int i=0; i<n; ++i)
    {
        getline(f, telepules[i], '\n');
        cout << telepules[i] << endl;
    }

    cout << "\nMadarak:\n";
    faj.resize(m);
    for(int j=0; j<m; ++j)
    {
        f >> faj[j];
        cout << faj[j] << endl;
    }

    cout << "\nNaplo:\n";
    naplo.resize(n);
    for(int i=0; i<(int)telepules.size(); ++i)
    {
        naplo[i].resize(m);
        cout << telepules[i] << " meresek\n";
        for(int j=0; j<(int)faj.size(); ++j)
        {
            f >> naplo[i][j];
            cout << "\t" << faj[j] << ": " << naplo[i][j];
        }
        cout << endl;
    }
}

//Feladat: 	Eldönti egy egész számról, hogy helyes meresi ertek-e.
//Bemenő adatok:int n	- egész szám
//Kimenő adatok:bool l	- vizsgálat eredménye: visszatérési érték
//Tevékenység:	Eldönti egy egész számról, hogy 1-nel nagyobb.
bool madarszam(int k)
{
    return 0<=k;
}

//Feladat: 	Eldönti egy egész számról, hogy 1, 2 vagy 3 értékű-e.
//Bemenő adatok:int s	- egész szám
//Kimenő adatok:bool l	- vizsgálat eredménye: visszatérési érték
//Tevékenység:	Eldönti egy egész számról, hogy 1, 2 vagy 3 értékű-e.
bool egykettoharom(int k)
{
    return k>=1 && k<=3;
}
