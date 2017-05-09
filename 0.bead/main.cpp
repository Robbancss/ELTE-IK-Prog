//Készítette:    Pánczél Róbert
//Dátum:         2017.03.01.
//neptun kód:    EY2P3W
//mail:          robi.panczel@gmail.com
//csoport:       0.csoport
//Feladat:       0.beadandó/8.feladat
//               Egymást követő napokon megmértük a napi hőmérsékletet, és ezeket az értékeket egy tömbben
//               tároljuk. Igaz-e, hogy egyik nap sem volt a hőmérséklet fagypont alatt?

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool Allzero(const vector<double> t);
bool ReadFromFile(const string &fname, vector<double> &t);

int main(int argc, char *argv[])
{
    char ch;
    do{
        vector<double> t;

    // Adatok beolvasása fájlból
        string fname;
        if(argc>1)
            fname = argv[1];
        else{
            cout << "Adja meg a szoveges fajl nevet: ";
            cin >> fname;
        }
        if (!ReadFromFile(fname, t)) break;
    //Adatok kiírás
        cout << "A fajl ezeket az adatokat tartalmazta: " ;
        for (int i=0; i<(int)t.size(); ++i){
            cout << t[i] << " ";
        }
        cout << "" << endl;
    // Kiértékelés és kiíratás
        if (Allzero(t) && (int)t.size()==0) {
                cout << "Nincs mert adat" << endl;
        }
        else if(Allzero(t)) {
                cout << "Nem volt fagypont alatti mert adat"<< endl;
        }
        else             {
                cout << "Volt fagypont alatti mert adat"<< endl;
        }

        cout << endl << "Futtassam ujra? (I/N) "; cin  >> ch;
        argc = 1;
    }while(ch!='n' && ch!='N');

    return 0;
}

//Feladat:      A doubleket tartalmazó tömb (vector) feltöltése txt állományból
//Tevékenység:  Megnyitja a megadott szöveges állományt (sikertelen kísérlet esetén hibát jelez)
//              majd a fájlból egymás után beolvassa az összes elválasztójelekkel határolt doubleket
//              és elhelyezi azokat egy tömbben (vector-ban)
//Bemenõ adat:  string fname - szöveges állomány neve
//Kimenõ adat:  vector<int> t
//              bool ok - sikerült-e az állomány megnyitása (visszatérési értékként)
bool ReadFromFile(const string &fname, vector<double> &t)
{
    // Fájl feldolgozása
    ifstream x(fname.c_str());
    if(x.fail()){
        cout << "Hibas fajlnev!"<< endl;
        return false;
    }

    // Vector feltöltése
    double data;
    x >> data;

    while(!x.eof()){
        t.push_back(data);
        x >> data;
    }
    // Ha nem volt az utolsó sor végén sorvége jel:
    if (!x.fail()) t.push_back(data);
    return true;
}

//Feladat:      Eldönti, hogy volt-e fagypont alatti mért érték
//Tevékenység:  Optimista eldöntéssel megvizsgálja, hogy a tömb (vector) minden elemére teljesül, hogy nincs fagypont alatt
//Bemenõ adat:  vector<double> t
//Kimenõ adat:  bool l - a válasz visszatérési értékként
bool Allzero(const vector<double> t)
{
    bool l = true;
    for(int i=0; l && i<(int)t.size(); ++i){
        l = t[i]>=0;
    }
    return l;
}


