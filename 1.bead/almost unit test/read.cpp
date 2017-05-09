//Készítette:    Pánczél Róbert
//Dátum:         2017.04.15.
//NEPTUN kód:    EY2P3W
//Mail:          robi.panczel@gmail.com
//Csoport:       06. csoport
//Feladat:

#include "read.h"
#include <iostream>

using namespace std;

bool all(int k) {return true;}
bool nat(int k) {return k>=0;}
bool neg(int k) {return k<0;}

//Feladat: 	Megadott feltételt kielégítő egész számot olvas be.
//Bemenő adatok:string msg	    - kiírandó üzenet
//				string err  	- kiírandó hibaüzenet
//              bool valid(int)- ellenőrző függvény
//Kimenő adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyűzetről olvas be egy a valid() feltételnek megfelelő
//		        egész számot.
int read_int(const string &msg, const string &err, bool valid(int))
{
    int n;
    bool hiba;
    do{
        cout << msg;
        cin >> n;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0 || !valid(n);
        if(hiba) cout << err << endl;
    }while(hiba);

    return n;
}
