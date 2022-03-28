#include "histogram.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

Histogram::Histogram()
{

}

Histogram::Histogram(std::vector<int> values)
{
    emplace(values);
}

void Histogram::emplace(int value)
{
    bins_[value] += 1;
}

void Histogram::emplace(const std::vector<int> &values)
{
    for(const auto& v: values)
    {
        emplace(v);
    }
}

Histogram& Histogram::operator<<(int value)
{
    emplace(value);
    return (*this);
}

int Histogram::operator[](int value)
{
    if(bins_.find(value) != bins_.end())
    {
        return bins_[value];
    }
    else
    {
        return 0;
    }
}

Histogram::operator std::vector<std::pair<int, int>>() const
{
    return unique_items();
}

void Histogram::from_csv(std::string path, char delimiter, int column_index)
{
    std::fstream fin;

    fin.open(path, std::ios::in);

    std::vector<std::string> row;
    std::string line, word, temp;

    while (fin >> temp) {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
//        getline(fin, line);

        // used for breaking words
        std::stringstream s(temp);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, delimiter)) {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        for(const auto &e:row)
        {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
        std::cout << "Liczba punktów: " << row[column_index] << std::endl;
        emplace(std::stoi(row[column_index]));
    }
}

void Histogram::clear()
{
    bins_.clear();
}

std::istream &operator>>(std::istream &str, Histogram &h)
{
    int value;
    str >> value;
    h.emplace(value);
    return str;
}

std::ostream &operator<<(std::ostream &str, const Histogram &h){
    for(auto const& [key, val] : h.bins_)
    {
        str << key << ':' << val << std::endl;
    }

    return str;
}

std::pair<int, int> Histogram::range()
{
    return std::make_pair(bins_.begin()->first, bins_.rbegin()->first);
}

template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  });
}

std::pair<int, int> Histogram::max() const
{
    return get_max(this->bins_);
}

std::vector<int> Histogram::unique_bins()
{
    std::vector<int> ub;
    for(auto const& [key, val] : bins_)
    {
        ub.emplace_back(key);
    }
    return ub;
}

std::vector<std::pair<int, int>> Histogram::unique_items() const
{
    std::vector<std::pair<int, int>> ui;
    for(auto const& item : bins_)
    {
        ui.emplace_back(item);
    }
    return ui;
}

void print(std::vector<std::pair<int, int>> bv)
{
    std::cout << "BinsVector: ";
    for(const auto &item : bv)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}
