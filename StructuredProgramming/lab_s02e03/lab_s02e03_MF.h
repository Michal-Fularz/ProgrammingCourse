#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina);

std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk);

bool operator==(const Roslina &r1, const Roslina &r2);

bool czy_jest_gruszka_find(const Koszyk &koszyk);
bool czy_jest_gruszka_find_if(const Koszyk &koszyk);
bool czy_jest_gruszka_for(const Koszyk &koszyk);

bool czy_same_owoce(const Koszyk &koszyk);

bool czy_same_warzywa(const Koszyk &koszyk);

bool czy_co_najmniej_jeden_owoc(const Koszyk &koszyk);

bool czy_co_najmniej_jedno_warzywo(const Koszyk &koszyk);

bool czy_co_najmniej_jeden_typu_v1(const Koszyk &koszyk, TypRosliny typ);

bool czy_co_najmniej_jeden_typu_v2(const Koszyk &koszyk, TypRosliny typ);

bool czy_zadnego_typu(const Koszyk &koszyk, TypRosliny typ);

int zlicz_owoce(const Koszyk &koszyk);

int zlicz_warzywa(const Koszyk &koszyk);

void usun_zaczynajace_sie_od(Koszyk &koszyk, char litera);

bool operator<(const Roslina &r1, const Roslina &r2);
