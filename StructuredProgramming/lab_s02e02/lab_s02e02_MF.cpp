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
            if (rates[i].usd > rates[j].usd)
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

size_t binary_search(const std::vector<double> &sorted_values, double value_to_find)
{
    size_t from = 0;
    size_t to = sorted_values.size()-1;

    while(to != from)
    {
        size_t middle_index = (to+from)/2;
        double middle_value = sorted_values[middle_index];

        if(middle_value == value_to_find)
        {
            return middle_index;
        }
        else if(middle_value > value_to_find)
        {
            to = middle_index - 1;
        }
        else if(middle_value < value_to_find)
        {
            from = middle_index + 1;
        }
    }

    if(sorted_values[to] == value_to_find)
    {
        return to;
    }

    return -1;

    /*
    int middle_index = (int)(sorted_values.size()/2);
    double middle_value = sorted_values[middle_index];

    if (middle_value == value_to_find)
    {
        return middle_index;
    }
    else if(middle_value > value_to_find)
    {
        std::vector<double> first_half(sorted_values.begin(), sorted_values.begin()+middle_index);
        return binary_search(first_half, value_to_find);
    }
    else if(middle_value < value_to_find)
    {
        std::vector<double> second_half(sorted_values.begin() + middle_index, sorted_values.end());
        return middle_index + binary_search(second_half, value_to_find);
    }
    */
}

size_t binary_search(const std::vector<Exchange_rate> &sorted_values_by_usd, double usd_rate_to_find)
{
    size_t from = 0;
    size_t to = sorted_values_by_usd.size()-1;

    while(to != from)
    {
        size_t middle_index = (to+from)/2;
        Exchange_rate middle_value = sorted_values_by_usd[middle_index];

        if(middle_value.usd == usd_rate_to_find)
        {
            return middle_index;
        }
        else if(middle_value.usd > usd_rate_to_find)
        {
            to = middle_index - 1;
        }
        else if(middle_value.usd < usd_rate_to_find)
        {
            from = middle_index + 1;
        }
    }

    if(sorted_values_by_usd[to].usd == usd_rate_to_find)
    {
        return to;
    }

    return -1;
}
