//Készítette:    Pánczél Róbert
//Dátum:         2017.04.15.
//NEPTUN kód:    EY2P3W
//Mail:          robi.panczel@gmail.com
//Csoport:       06. csoport
//Feladat:       Melyik az a telepules, ahol a legtobb madarfaj fordult elo?

#include <string>
#include <vector>

int legtobb_madarfajos_telepules(const std::vector<std::vector<int> > &naplo);
int madarfajDB(const std::vector<int> &v);

void neveket_olvas(int n, const std::string &str, std::vector<std::string> &v);
void madarakat_olvas(const std::vector<std::string> &telepules, const std::vector<std::string> &faj, std::vector<std::vector<int> > &a);

void fajlbol_olvas(const std::string &fajlnev, std::vector<std::string> &telepules, std::vector<std::string> &faj, std::vector<std::vector<int> > &naplo);

bool madarszam(int k);
bool egykettoharom(int k);
