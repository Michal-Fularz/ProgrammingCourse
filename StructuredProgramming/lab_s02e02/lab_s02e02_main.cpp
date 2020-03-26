#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "lab_s02e02_MF.h"


void ex_1()
{
    std::cout << "Exercise 1" << std::endl;

    std::string word = "racecar";
    do
    {
        std::cout << "Enter a word to check if it is a palindrome or type exit to break the loop" << std::endl;
        std::cin >> word;

        if (is_palindrome(word)) {
            std::cout << "It is a palindrome!" << std::endl;
        } else {
            std::cout << "Nope" << std::endl;
        }
    }
    while(word != "exit");

    std::cout << std::endl << std::endl;
}

void sort_ex_6(std::vector<int> a)
{
    // this is just an implementation of bubble sorting algorithm based on the diagram

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
                std::swap(a[i], a[i+1]);
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
    std::cout << "Exercise 8" << std::endl;
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

    sort_usd(rates);

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
}

int main()
{
    std::cout << "Hello lab 2!" << std::endl;

    ex_1();
    ex_8();

    // getline allows reading input with spaces
    std::string text;
    getline(std::cin, text);
    std::cout << text;

    return 0;
}
