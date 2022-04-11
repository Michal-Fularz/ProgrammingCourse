#include "histogram.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>


Histogram::Histogram(const std::vector<int> &data)
{
    emplace(data);
}

void Histogram::emplace(int v)
{
	this->bins_[v] += 1;
	// alternative:
    //if(bins_.find(v) == bins_.end())
    //{
    //    bins_[v] = 1;
    //}
    //else
    //{
    //    bins_[v] += 1;
    //}
}

void Histogram::emplace(const std::vector<int> &data)
{
    for(const auto &value: data)
    {
        emplace(value);
    }
}

void Histogram::clear()
{
    bins_.clear();
}

std::pair<int, int> Histogram::range() const{
    return {bins_.begin()->first, bins_.rbegin()->first};
	// alternative:
	//return std::make_pair(bins_.begin()->first, bins_.rbegin()->first);
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
    return get_max(bins_);
}

std::vector<int> Histogram::unique_bins() const
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

Histogram& Histogram::operator<<(int v)
{
    emplace(v);
    return (*this);
}

int Histogram::operator[](int v) const
{
    if(bins_.find(v) == bins_.end())
    {
        return 0;
    }
    else
    {
        return bins_.at(v);
    }
}

Histogram::operator BinsVector()
{
    BinsVector bv;
    for(const auto [bin, frequency] : bins_)
    {
        bv.push_back(std::make_pair(bin, frequency));
    }
    return bv;
}

//Histogram::operator std::vector<std::pair<int, int>>()
//{
//    return unique_items();
//}

bool Histogram::from_csv(const std::string& path, char delimiter, int column_index)
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

std::istream &operator>>(std::istream &str, Histogram &hist)
{
    int value;
    str >> value;
    hist.emplace(value);

    return str;
}

std::ostream &operator<<(std::ostream &str, const Histogram &hist)
{
    for(auto const &[bin, frequency] : hist.bins_)
    {
          str << bin << ":" << frequency << std::endl;
    }

    return str;
}

Histogram Histogram::rand(int min, int max, int count)
{
    Histogram h;
    for(int i=0; i<count; i++)
    {
        int value = std::rand()%(max-min) + min;
        h.emplace(value);
    }
    return h;
}

Histogram Histogram::generate(int min, int max, int count)
{
    Histogram h;
    for (int i = min; i < max; i++)
        for(int j=0; j<count; j++)
        {
            h.emplace(i);
        }
    return h;
}

Histogram Histogram::generate(int count, int (*func_ptr)())
{
    Histogram h;
    for (int i = 0; i < count; i++)
        h.emplace(func_ptr());
    return h;
}

void print(const std::vector<std::pair<int, int>> &bv)
{
	std::cout << "BinsVector: " << std::endl;
    for(const auto &item : bv)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}
