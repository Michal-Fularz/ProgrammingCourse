#include "lab_s02e02_MF.h"

#include <iostream>


void Exchange_rate::print()
{
    std::cout << "date: " << date << ", usd: " << usd;
    std::cout << "eur: " << eur << ", table_id: " << table_id << std::endl;
}

void sort_usd(std::vector<Exchange_rate>& rates)
{
    for(size_t i=0; i<rates.size()-1; i++)
    {
        for(size_t j=i+1; j<rates.size(); j++)
        {
            if (rates[i].usd < rates[j].usd)
            {
                std::swap(rates[i], rates[j]);
            }
        }
    }
}

bool is_palindrome(std::string word)
{
    for(size_t i=0; i<word.size()/2; i++)
    {
        if (word[i] != word[word.size()-1-i])
        {
            return false;
        }
    }
    return true;
}

std::vector<size_t> find_all(const std::string& text, char sign)
{
    std::vector<size_t> indices_of_sign;

    size_t index_of_sign = text.find(sign);

    while(index_of_sign != std::string::npos)
    {
        indices_of_sign.emplace_back(index_of_sign);
        index_of_sign = text.find(sign, index_of_sign+1);
    }

    return indices_of_sign;
}
