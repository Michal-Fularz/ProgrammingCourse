#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>


void ex7()
{
    std::cout << std::endl << "Zad 7" << std::endl;
    std::vector<std::string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};

    std::regex re(R"(((PO)|(PZ)) ?[A-Z0-9]{5})");
    std::smatch m;

    for (auto &l : lines)
    {
        if(std::regex_search(l, m, re))
        {
            std::cout << m[0] << std::endl;
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

//    ex7();
//    ex_tuple();
    ex_homework();



    return 0;
}
