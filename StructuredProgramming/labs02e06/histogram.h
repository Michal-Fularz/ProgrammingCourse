#pragma once

#include <vector>
#include <map>
#include <string>

class Histogram
{
public:
    Histogram();
    Histogram(std::vector<int> values);

    void emplace(int value);
    void emplace(const std::vector<int> &values);

    Histogram& operator<<(int value);
    int operator[](int value);
    operator std::vector<std::pair<int, int>>() const;

    friend std::istream &operator>>(std::istream &str, Histogram &h);
    friend std::ostream &operator<<(std::ostream &str, const Histogram &h);

    void from_csv(std::string path, char delimiter, int column_index);

    void clear();

    std::pair<int, int> range();
    std::pair<int, int> max() const;
    std::vector<int> unique_bins();
    std::vector<std::pair<int, int>> unique_items() const;

private:
    std::map<int, int> bins_;

};

void print(std::vector<std::pair<int, int>> bv);
