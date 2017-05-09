#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <string>
#include <vector>
#include "naplo.h"

using namespace std;

TEST_CASE("intervallum hossza 0", "n×0 matrix")
{
    vector<vector<int> > naplo;
    vector<string>      telepules; //telepules
    vector<string>      faj; //targy
    int n,m;

    fajlbol_olvas("t03.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("intervallum hossza 1", "1×m matrix")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t11_1.txt", telepules, faj, naplo);
    CHECK_FALSE(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("intervallum hossza tobb", "n×m matrix")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t33_213.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("intervallum eleje", "elso telepules nincs madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t32_122.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("intervallum vege", "utolso telepulesen nincs madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t32_221.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("eredmeny pozitiv", "minden telepulesen van madar")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t32_222.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}

TEST_CASE("eredmeny negativ", "elso illetve utolso telepulesen egyenlo madarszam")
{
    vector<vector<int> > naplo;
    vector<string>      telepules;
    vector<string>      faj;
    int n,m;

    fajlbol_olvas("t32_110.txt", telepules, faj, naplo);
    CHECK(legtobb_madarfajos_telepules(naplo));
}
