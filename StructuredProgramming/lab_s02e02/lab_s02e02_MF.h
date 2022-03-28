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

std::vector<size_t> find_all(const std::string& text, char sign);

size_t binary_search(const std::vector<double> &sorted_values, double value_to_find);

size_t binary_search(const std::vector<Exchange_rate> &sorted_values_by_usd, double usd_rate_to_find);
