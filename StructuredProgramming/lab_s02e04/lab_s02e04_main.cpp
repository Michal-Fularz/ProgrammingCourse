#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>


void ex_7()
{
    std::cout << std::endl << "ex_7" << std::endl;
    std::vector<std::string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};

    std::regex re(R"(((PO)|(PZ)) ?[A-Z0-9]{5})");
    // alternative: ((((PO)|(PZ)) ?\w{5}))
    std::smatch m;

    for (auto &l : lines)
    {
        if(std::regex_search(l, m, re))
        {
            std::cout << m[0] << std::endl;
        }
    }
}

void ex_8()
{
    std::cout << std::endl << "ex_8" << std::endl;

    std::fstream input_file("./../lab_s02e04/numeryTelefonowGoogle.html", std::ios::in);
    if(input_file.is_open())
    {
          std::stringstream str_stream;
          str_stream << input_file.rdbuf(); //przepisuje zawartość pliku do strumienia
          std::string full_text = str_stream.str(); //zapisuje całą zawartość strumienia do std::string
          //std::regex re(R"((((00)|(\+))(\d{2}))?((( |-)?)\d){9})");
          std::regex re(R"(\W{2}(0?|\+\d{2}|00\d{2})(((-|\s|[\(\)])*\d){9})\D)");
          std::smatch sm;
          while (regex_search(full_text, sm, re))
          {
                std::cout << sm[0] << std::endl; //Podciąg dla którego wzorzec jest w pełni dopasowany
                full_text = sm.suffix(); //przycięcie napisu do przeszukania
          }
    }
}

std::tuple<char, int, bool> mytuple() {
    char a = 'a';
    int i = 123;
    bool b = true;
    return {a, i, b};// lub std::make_tuple(a, i, b);
}

void ex_tuple()
{
    auto [a, i, b] = mytuple();
    std::cout << "a: " << a << ", i: " << i <<  ", b: " << b << std::endl;
}

void ex_final()
{
    std::cout << std::endl << "Final excersise" << std::endl;
    std::map<std::string, int> word_statistics;
    std::fstream input_file("./../data/lab_s02e04/license.txt", std::ios::in);
    if(input_file.is_open())
    {
        while (!input_file.eof())
        {
              std::string word;
              input_file >> word;
              std::regex re(R"(\W*([A-Za-z\-]+)\W*)");
              std::smatch m;
              std::regex_search (word, m, re); //zwróci wartość true
              if(!m.empty())
              {
                  std::string w = m[1];
                  std::transform(w.begin(), w.end(), w.begin(), [](const auto &c){ return std::tolower(c); });
                  std::cout << w << std::endl;
                  word_statistics[w] += 1;
              }
        }
    }
    for(auto [word, frequency] : word_statistics)
    {
          std::cout<< word << " - " << frequency << std::endl;
    }
    std::vector<std::pair<std::string,int>> word_statistics_vector;
    std::copy(word_statistics.begin(), word_statistics.end(), std::back_inserter(word_statistics_vector));
    std::sort(word_statistics_vector.begin(), word_statistics_vector.end(),
              [](const std::pair<std::string,int> &a, const std::pair<std::string,int> &b){
        return a.second > b.second;
    });
    std::fstream output("word_stats.txt", std::ios::out);
    if (output.is_open())
    {
        for(auto w : word_statistics_vector)
        {
            output << w.first << " - " << w.second << std::endl;
        }
        output.close();
    }
}

std::string normalize_phone_number(const std::string &n)
{
    auto normalized_phone_number = n;
    // TODO(MF) function for normalization
    return normalized_phone_number;
}

void ex_homework()
{
    std::fstream input_file("./../data/lab_s02e04/file1.html", std::ios::in);
    if(input_file.is_open()){
          std::stringstream str_stream;
          str_stream << input_file.rdbuf(); //przepisuje zawartość pliku do strumienia
          std::string full_text = str_stream.str(); //zapisuje całą zawartość strumienia do std::string

          std::cout << full_text << std::endl;

          std::regex re(R"((Tel. (\d{2,3} \d{2,3} \d{2,3} \d{2,3}))|(tel.{1,7}(\d{2,3} \d{2,3} \d{2,3} \d{2,3})))");
          std::smatch sm;

          std::string text = full_text;

          std::map<std::string, int> word_statistics;


          while (regex_search(text, sm, re)) {
                std::cout << sm[0] << std::endl; //Podciąg dla którego wzorzec jest w pełni dopasowany
                std::cout << "Group 2: " << sm[2] << std::endl << std::endl;
                std::cout << "Group 4: " << sm[4] << std::endl << std::endl;

                for(const auto &c : sm[2].str())
                {

                }

                text = sm.suffix(); //przycięcie napisu do przeszukania
          }
    }
}


int main()
{
    std::cout << "Hello lab04!" << std::endl;

    // ex_3:
    // ((PO)|(PZ))[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]

    // ex_4:
    // (([A-Z]{2})|([A-Z]{3}))\w{5}

    // ex_5:
    // (((00)|(\+))(\d{2}))?((( |-)?)\d){9}
    // \W{2}(0?|\+\d{2}|00\d{2})(((-|\s|(<[^>]+>)|[\(\)])*\d){9})\D

    {
            std::cout << "regex_match" << std::endl;
            std::regex re(R"(\d+)");
            std::smatch m;
            std::string text = "1234";
            std::cout << std::regex_match (text, m, re) << " " << m[0] << std::endl; //zwróci wartość true
            text = "1234m";
            std::cout <<  std::regex_match (text, m, re) << " "<< m[0] << std::endl; //zwróci wartość false
        }
        {
            std::cout << std::endl << "regex_search" << std::endl;
            std::regex re("(\\d+)");
            std::smatch m;
            std::string text = "1234";
            std::cout <<  std::regex_search (text, m, re)  << " " << m[0] << std::endl; //zwróci wartość true
            text = "1234m 78910";
            std::cout <<  std::regex_search(text, m, re)   << " " << m[0] << " " << m[1] << std::endl; //zwróci wartość true i zwróci do m pierwszy pasujący podciąg czyli 1234
        }
        {
            std::cout << std::endl << "regex_search all" << std::endl;
            std::string log(R"(
                  Speed: 366
                  Mass: 35
                  Speed: 378
                  Mass: 32
                  Speed: 400
                  Mass: 30)");
            std::regex re(R"(Speed:\s(\d+))");
            std::smatch sm;
            while (regex_search(log, sm, re))
            {
                  std::cout << sm[0] << std::endl; //Podciąg dla którego wzorzec jest w pełni dopasowany
                  std::cout << "Group 1: " << sm[1] << std::endl << std::endl; //grupa nr 1 (\d*)
                  log = sm.suffix(); //przycięcie napisu do przeszukania
            }
        }
        {
            std::cout << std::endl << "regex_iterator" << std::endl;
            std::string log(R"(
                  Speed: 366
                  Mass: 35
                  Speed: 378
                  Mass: 32
                  Speed: 400
                  Mass: 30)");
            std::regex re(R"(Speed:\s(\d+))");
            auto words_begin = std::sregex_iterator(log.begin(), log.end(), re);
            auto words_end = std::sregex_iterator();
            std::cout << "Found " << std::distance(words_begin, words_end) << " full matches:" << std::endl;;
            for (auto i = words_begin; i != words_end; ++i)
            {
                std::smatch match = *i;
                std::cout << match[0] << std::endl;
                std::cout << "Group 1: " << match[1] << std::endl << std::endl;
            }
        }

    ex_7();
    ex_8();

    ex_tuple();

    {
        std::cout << std::endl;
        //para z wartościami domyślnymi "" i 0:
        std::pair<std::string, double> exchange_rate_empty;
        //zmiana wartości pary:
        exchange_rate_empty = {"EUR", 4.5}; // lub std::make_pair<string,double>("EUR",4.5);
        //definicja para z zainicjowaną dwoma wartościami:
        std::pair<std::string, double> exchange_rate_usd("usd",4.10);
        //odwołanie się do pól first i second
        std::cout<< "currency: "<< exchange_rate_usd.first << " - rate: "<< exchange_rate_usd.second << std::endl;
        //lub z użyciem structured binding od C++17
        auto[currency, rate] = exchange_rate_usd;
        std::cout<< "currency: "<< currency << " - rate: "<< rate << std::endl << std::endl;
        auto [a, i, b] = mytuple();
        std::cout<< "a: "<< a << " i: " << i << " b: " << b << std::endl << std::endl;
    }

    {
        std::cout << std::endl;
        std::map<std::string, int> word_statistics;
        //word_statistics.emplace("the",1);
        word_statistics["the"] = 1;
        std::cout << word_statistics["the"] << std::endl; //zostanie wartość 1
        std::cout << word_statistics["computer"] << std::endl; //element nie istnieje, zostanie utworzony i przypisana zostanie wartość domyślna dla int ->0
        std::string word2find = "elephant";
        try{
              int val = word_statistics.at(word2find);
              std::cout << val << std::endl;
        }
        catch(std::out_of_range e){
              std::cout << "Exception: " << e.what() << std::endl;
        }
        for(auto it = word_statistics.begin(); it != word_statistics.end(); it++) //gdzie it jest iteratorem typu: std::map<std::string,int>::iterator
        {
              std::cout<< it->first << " - " << it->second<< std::endl; //wyświetla klucz i wartosc poszczególnych elementów listy
        }
        //lub z wykorzystaniem structure binding i for range loop
        for(auto [word, frequency] : word_statistics){ //rzytowanie klucza i warości elementu na zmienną word (klucz) i frequency (wartość)
              std::cout<< word << " - " << frequency << std::endl;
        }
    }

    ex_final();

    ex_homework();

    return 0;
}
