//#ifndef LAB_S02E02_MF_H
//#define LAB_S02E02_MF_H
#pragma once

#include <string>
#include <vector>

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;

    void print();
};

void sort_usd(std::vector<Exchange_rate>& rates);

bool is_palindrome(std::string word);

//#endif // LAB_S02E02_H
