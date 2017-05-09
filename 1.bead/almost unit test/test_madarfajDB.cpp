#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "naplo.h"

using namespace std;

TEST_CASE("intervallum hossza 0", "nincs madarfaj")
{
    vector<vector<int> > naplo;
    vector<string>      telepules; //tanulo
    vector<string>      faj; //targy
    int n,m;

    fajlbol_olvas("t20.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==0);
}

TEST_CASE("intervallum hossza 1", "1 madarfaj 1 madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t11_1.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==1);
}

TEST_CASE("intervallum hossza tobb", "tobb faj csak 1 madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t14_1.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==1);
}

TEST_CASE("intervallum eleje es vege", "egy telepules 3 madar faj a kozepso 0")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t14_2.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==2);
}

TEST_CASE("eredmeny 0", "nincs madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t14_0.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==0);
}

TEST_CASE("eredmeny 1", "1 madar van csaj")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t14_1.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==1);
}

TEST_CASE("eredmeny 2", "1 telepulesen 2 madar van 1-1 mindkettobol")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t14_2.txt", telepules, faj, naplo);
    CHECK(madarfajDB(naplo[0])==2);
}

TEST_CASE("eredmeny 3", "1 telepules 4 madar osszesen")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      targy;
    int n,m;

    fajlbol_olvas("t14_3.txt", telepules, targy, naplo);
    CHECK(madarfajDB(naplo[0])==4);
}
