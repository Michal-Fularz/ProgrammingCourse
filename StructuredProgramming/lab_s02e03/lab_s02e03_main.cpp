#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "lab_s02e03_MF.h"
#include "./../lab_s02e02/lab_s02e02_MF.h"


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

void ex16()
{
    std::cout << "ex16" << std::endl;

    // relative location - works on each machine if the files are located in the same way relative to each other
    std::fstream file("./../data/kursy_usd_eur.csv"); //plik znajduje się w tym samym katalogu co pliki źródłowe projektu, inaczej trzeba podać pełną ścieżkę np. "c:/Users/nazwa_uzytkownika/Downloads/kursy_usd_eur.csv"
    // absolute location - unless all the folders on the path are named the same this will not work on different computers. This way should be avoided
    std::fstream file2("F:/Projects/university_courses/ProgrammingCourse/StructuredProgramming/data/kursy_usd_eur.csv");
    std::vector<Exchange_rate> rates;
    if (file.is_open()) {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }

    std::cout << "Data from the file:" << std::endl;
    for(const auto& r: rates)
    {
        std::cout << "date: " << r.date << ", usd: " << r.usd;
        std::cout << "eur: " << r.eur << ", table_id: " << r.table_id << std::endl;
    }
    std::cout << std::endl << std::endl;

//    sort_usd(rates);
    std::sort(
                rates.begin(),
                rates.end(),
                [](const Exchange_rate& r1, const Exchange_rate& r2 ) {
        return r1.usd < r2.usd;
    });

    std::cout << "Data sorted:" << std::endl;
    for(const auto& r: rates)
    {
        std::cout << "date: " << r.date << ", usd: " << r.usd;
        std::cout << "eur: " << r.eur << ", table_id: " << r.table_id << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::cout << "Ten entries with the largest amount of USD:" << std::endl;
    for(size_t i=0; i<10 && i<rates.size(); i++)
    {
        rates[i].print();
    }
    std::cout << std::endl << std::endl;

    Exchange_rate rate_to_find;
    rate_to_find.usd = 3.9011;

    const auto p = std::equal_range(
        rates.begin(),
        rates.end(),
        rate_to_find,
        [](const Exchange_rate& r1, const Exchange_rate& r2 ) {
            return r1.usd < r2.usd;
    });

    for(auto i = p.first; i != p.second; ++i)
    {
        std::cout << "USD rate of " << 3.9011 << " address: " << &(*i) << std::endl;
        i->print();
    }
    std::cout << std::endl << std::endl;

    int index = binary_search(rates, 3.9011);
    std::cout << "USD rate of " << 3.9011 << " index: " << index << std::endl;
    rates[index].print();
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
    ex16();

    return 0;
}
