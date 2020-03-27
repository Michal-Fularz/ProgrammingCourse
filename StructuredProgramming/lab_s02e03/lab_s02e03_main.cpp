#include <iostream>
#include <vector>

#include "lab_s02e03_MF.h"


// NOTE(MF): alterntaive to overloaded <<
void print_koszyk(const Koszyk& koszyk)
{
    for(auto& r : koszyk)
    {
        if(r.typ == TypRosliny::Owoc)
        {
            std::cout << "Owoc: " << r.nazwa;
        }
        else if(r.typ == TypRosliny::Warzywo)
        {
            std::cout << "Warzywo: " << r.nazwa;
        }
        else
        {
            std::cout << "Nieznana roslina: " << r.nazwa;
        }
        std::cout << std::endl;
    }
}

void ex8(const Koszyk &koszyk)
{
    std::cout << "ex8" << std::endl;

    std::cout << koszyk << std::endl;
    print_koszyk(koszyk);

    std::cout << std::endl << std::endl;
}

void ex9(const Koszyk &koszyk)
{
    std::cout << "ex9" << std::endl;

    if(czy_jest_gruszka_find_if(koszyk))
    {
        std::cout << "Jest gruszka!" << std::endl;
    }
    else
    {
        std::cout << "Nie ma gruszki!" << std::endl;
    }

    if(czy_jest_gruszka_find(koszyk))
    {
        std::cout << "Jest gruszka!" << std::endl;
    }
    else
    {
        std::cout << "Nie ma gruszki!" << std::endl;
    }

    if(czy_jest_gruszka_for(koszyk))
    {
        std::cout << "Jest gruszka!" << std::endl;
    }
    else
    {
        std::cout << "Nie ma gruszki!" << std::endl;
    }

    std::cout << std::endl << std::endl;
}

void ex10(const Koszyk &koszyk)
{
    std::cout << "ex10" << std::endl;

    if(czy_same_owoce(koszyk))
    {
        std::cout << "Same owoce!" << std::endl;
    }
    else if(czy_same_warzywa(koszyk))
    {
        std::cout << "Same warzywa!" << std::endl;
    }
    else
    {
        std::cout << "Owoce i warzywa!" << std::endl;
    }

    if(czy_co_najmniej_jeden_owoc(koszyk))
    {
        std::cout << "Przynajmniej jeden owoc!" << std::endl;
    }
    if(czy_co_najmniej_jedno_warzywo(koszyk))
    {
        std::cout << "Przynajmniej jedno warzywo!" << std::endl;
    }
    if(!czy_co_najmniej_jeden_owoc(koszyk) && !czy_co_najmniej_jedno_warzywo(koszyk))
    {
        std::cout << "Brak owocow i warzyw!" << std::endl;
    }

    if(czy_zadnego_typu(koszyk, TypRosliny::Owoc))
    {
        std::cout << "Brak owowcow!" << std::endl;
    }
    if(czy_zadnego_typu(koszyk, TypRosliny::Warzywo))
    {
        std::cout << "Brak warzyw!" << std::endl;
    }
    if(!czy_zadnego_typu(koszyk, TypRosliny::Owoc) && !czy_zadnego_typu(koszyk, TypRosliny::Warzywo))
    {
        std::cout << "Sa owoce i warzywa!" << std::endl;
    }

    std::cout << std::endl << std::endl;
}

void ex11(const Koszyk &koszyk)
{
    std::cout << "ex11" << std::endl;

    std::cout << "W koszyku jest " << zlicz_owoce(koszyk) << " owocow i " << zlicz_warzywa(koszyk) << " warzyw" << std::endl;

    std::cout << std::endl << std::endl;
}

void ex12(Koszyk &koszyk)
{
    std::cout << "ex12" << std::endl;

    usun_zaczynajace_sie_od(koszyk, 'g');
    std::cout << koszyk << std::endl;

    std::cout << std::endl << std::endl;
}

void ex13(Koszyk& koszyk)
{
    std::cout << "ex13" << std::endl;

    std::sort(koszyk.begin(), koszyk.end());
    std::cout << koszyk << std::endl;

    std::cout << std::endl << std::endl;
}

void ex14()
{
    std::cout << "ex14" << std::endl;

    Koszyk k1 {
        Roslina{TypRosliny::Owoc, "Banan"},
        Roslina{TypRosliny::Warzywo, "Marchew"},
        Roslina{TypRosliny::Owoc, "Gruszka"}
    };

    Koszyk k2 {
        Roslina{TypRosliny::Owoc, "Banan"},
        Roslina{TypRosliny::Warzywo, "Ziemniak"},
        Roslina{TypRosliny::Warzywo, "Marchew"}
    };

    std::sort(k1.begin(), k1.end());
    std::sort(k2.begin(), k2.end());

    Koszyk koszyk_wspolne;
    std::set_intersection(
                k1.begin(), k1.end(),
                k2.begin(), k2.end(),
                std::back_inserter(koszyk_wspolne)
    );
    std::cout << koszyk_wspolne << std::endl;

    Koszyk koszyk_roznica;
    std::set_difference(
                k1.begin(), k1.end(),
                k2.begin(), k2.end(),
                std::back_inserter(koszyk_roznica)
    );
    std::cout << koszyk_roznica << std::endl;

    Koszyk koszyk_suma;
    std::set_union(
                k1.begin(), k1.end(),
                k2.begin(), k2.end(),
                std::back_inserter(koszyk_suma)
    );
    std::cout << koszyk_suma << std::endl;

    std::cout << std::endl << std::endl;
}


int main()
{
    std::cout << "Hello lab03!" << std::endl;

    Koszyk koszyk;
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "Banan"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "Jablko"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "Pomarancza"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "gruszka"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "Brzoskwinia"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "grejpfrut"});
    koszyk.emplace_back(Roslina{TypRosliny::Owoc, "Gumijagody"});
    koszyk.emplace_back(Roslina{TypRosliny::Warzywo, "Marchew"});
    koszyk.emplace_back(Roslina{TypRosliny::Warzywo, "Seler"});
    koszyk.emplace_back(Roslina{TypRosliny::Warzywo, "Por"});
    koszyk.emplace_back(Roslina{TypRosliny::Warzywo, "Ziemniak"});

    ex8(koszyk);
    ex9(koszyk);
    ex10(koszyk);
    ex11(koszyk);
    ex12(koszyk);
    ex13(koszyk);
    ex14();

    return 0;
}
