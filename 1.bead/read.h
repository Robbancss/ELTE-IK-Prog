//Készítette:    Pánczél Róbert
//Dátum:         2017.04.15.
//NEPTUN kód:    EY2P3W
//Mail:          robi.panczel@gmail.com
//Csoport:       06. csoport
//Feladat:

#ifndef _READ_
#define _READ_

#include <string>

bool all(int k);
bool nat(int k);
bool neg(int k);

int read_int(const std::string &msg, const std::string &err, bool valid(int) = all);

#endif
