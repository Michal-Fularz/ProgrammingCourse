#include "histogram.h"

#include <iostream>
#include <algorithm>


Histogram::Histogram(const std::vector<int> &data)
{
    emplace(data);
}

void Histogram::emplace(int v)
{
    if(bins_.find(v) == bins_.end())
    {
        bins_[v] = 1;
    }
    else
    {
        bins_[v] += 1;
    }
}

void Histogram::emplace(const std::vector<int> &data)
{
    for(const auto &value: data)
    {
        emplace(value);
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
    for(auto [bin, frequency] : hist.bins_)
    {
          str << bin << " - " << frequency << std::endl;
    }

    return str;
}

void Histogram::clear()
{
    bins_.clear();
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

std::pair<int, int> Histogram::range() const{
    return {bins_.begin()->first, bins_.rbegin()->first};
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

Histogram& Histogram::operator<<(int v)
{
    emplace(v);
    return *this;
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
    for(const auto &elem : bv)
    {
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}
