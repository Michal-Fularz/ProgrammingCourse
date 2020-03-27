#include "lab_s02e03_MF.h"

#include <iostream>


std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk)
{
    for(auto& r : koszyk)
    {
        out << r << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream &out, const Roslina &roslina)
{
    if(roslina.typ == TypRosliny::Owoc)
    {
        out << "Owoc: " << roslina.nazwa;
    }
    else if(roslina.typ == TypRosliny::Warzywo)
    {
        out << "Warzywo: " << roslina.nazwa;
    }
    else
    {
        out << "Nieznana roslina: " << roslina.nazwa;
    }
    return out;
}

std::string to_upper(const std::string &s)
{
    // NOTE(MF): copying is required, as the string will be modified
    auto result = s;

    // NOTE(MF): approach 1
    for (auto &c: result) c = toupper(c);
    // NOTE(MF): approach 2
    // std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    return result;
}

bool operator==(const Roslina &r1, const Roslina &r2)
{
    return to_upper(r1.nazwa) == to_upper(r2.nazwa);
}

// NOTE(MF): approach with std::find that uses the above operator==
bool czy_jest_gruszka_find(const Koszyk &koszyk)
{
    std::string name_to_compare = "Gruszka";

    auto itr_gruszka = std::find(koszyk.begin(), koszyk.end(), Roslina{TypRosliny::Owoc, name_to_compare});

    if (itr_gruszka != koszyk.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// NOTE(MF): std::find_if approach
bool czy_jest_gruszka_find_if(const Koszyk &koszyk)
{
    std::string name_to_compare = "Gruszka";

    auto itr_gruszka = std::find_if(
                koszyk.begin(),
                koszyk.end(),
                [name_to_compare](const Roslina &r)
                {
                    return to_upper(r.nazwa) == to_upper(name_to_compare);
                }
    );

    if (itr_gruszka != koszyk.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// NOTEW(MF): manual comparison
bool czy_jest_gruszka_for(const Koszyk &koszyk)
{
    std::string name_to_compare = "Gruszka";

    for(const auto &r: koszyk)
    {
        if(to_upper(r.nazwa) == to_upper(name_to_compare))
        {
            return true;
        }
    }
    return false;
}

bool czy_same_owoce(const Koszyk &koszyk)
{
    std::string name_to_compare = "Gruszka";
    return std::all_of(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina &roslina){ return roslina.typ == TypRosliny::Owoc; }
    );
}

bool czy_same_warzywa(const Koszyk &koszyk)
{
    return std::all_of(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina& roslina){ return roslina.typ == TypRosliny::Warzywo; }
    );
}

bool czy_co_najmniej_jeden_owoc(const Koszyk &koszyk)
{
    return std::any_of(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

bool czy_co_najmniej_jedno_warzywo(const Koszyk &koszyk)
{
    return std::any_of(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
    );
}

bool czy_co_najmniej_jeden_typu_v1(const Koszyk &koszyk, TypRosliny typ)
{
    if(typ == TypRosliny::Owoc)
        return czy_co_najmniej_jeden_owoc(koszyk);
    else
        return  czy_co_najmniej_jedno_warzywo(koszyk);
}

bool czy_co_najmniej_jeden_typu_v2(const Koszyk &koszyk, TypRosliny typ)
{
    return std::any_of(
                koszyk.begin(),
                koszyk.end(),
                [typ](const Roslina &roslina) { return roslina.typ == typ; }
    );
}

bool czy_zadnego_typu(const Koszyk &koszyk, TypRosliny typ)
{
    return std::none_of(
                koszyk.begin(),
                koszyk.end(),
                [typ](const Roslina &roslina) { return roslina.typ == typ; }
    );
}

int zlicz_owoce(const Koszyk &koszyk)
{
    return std::count_if(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina &roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

int zlicz_warzywa(const Koszyk &koszyk)
{
    return std::count_if(
                koszyk.begin(),
                koszyk.end(),
                [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
    );
}

void usun_zaczynajace_sie_od(Koszyk &koszyk, char litera)
{
    auto czy_zaczyna = [litera](const Roslina &r)
    {
        return std::toupper(r.nazwa[0]) == std::toupper(litera);
    };

    koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(), czy_zaczyna), koszyk.end());
}

bool operator<(const Roslina &r1, const Roslina &r2)
{
    return r1.nazwa < r2.nazwa;
}
