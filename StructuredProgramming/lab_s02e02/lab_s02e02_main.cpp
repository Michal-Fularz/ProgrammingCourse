#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "lab_s02e02_MF.h"

using namespace std;

void ex_1()
{
    std::string word = "racecar";
    do
    {
        cout << "Enter word" << endl;
        cin >> word;

        if (is_palindrome(word)) {
            std::cout << "To palindrom!" << std::endl;
        } else {
            std::cout << "Nope" << std::endl;
        }
    }
    while(word != "exit");
}

void ex_5()
{
//    std::string input = "Ala ma kota, kot zjadl Ale!";
//    std::string output = find_and_replace(input, "kot", "hefalump");
    // wynik: "Ala ma hefalumpa, hefalump zjadl Ale!"
}

void sort_ex_6(vector<int> a)
{
    int rozmiar = a.size();
    bool flaga_zamiana = false;

    do
    {
        int i=0;
        flaga_zamiana = false;

        while(i<rozmiar-1)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                flaga_zamiana = true;
            }
            i++;
        }
        rozmiar--;
    }
    while(flaga_zamiana);

}

void ex_8()
{
    // lokalizacja względna
    std::fstream file2("./../data/kursy_usd_eur.csv"); //plik znajduje się w tym samym katalogu co pliki źródłowe projektu, inaczej trzeba podać pełną ścieżkę np. "c:/Users/nazwa_uzytkownika/Downloads/kursy_usd_eur.csv"
    // lokalizacja bezwzględna
    std::fstream file("F:/Projects/university_courses/ProgrammingCourse/StructuredProgramming/data/kursy_usd_eur.csv");
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

    for(const auto& r: rates)
    {
        cout << "date: " << r.date << ", usd: " << r.usd;
        cout << "eur: " << r.eur << ", table_id: " << r.table_id << endl;
    }
    cout << endl << endl;
    sort_usd(rates);
    cout << endl << endl;
    for(const auto& r: rates)
    {
        cout << "date: " << r.date << ", usd: " << r.usd;
        cout << "eur: " << r.eur << ", table_id: " << r.table_id << endl;
    }

    for(size_t i=0; i<10 && i<rates.size(); i++)
    {
        rates[i].print();
        cout << endl;
    }
}

int main()
{
    cout << "Hello lab 2!" << endl;

    ex_1();
//    ex_5();
    ex_8();
    string text;
    getline(cin, text);
    cout << text;

    return 0;
}
