#pragma once

#include <map>
#include <string>
#include <vector>
#include <utility>


using Bin = int; // alias typu wartości dla przedziału histogramu
using Frequency = int; // alias typu wartości dla częstości wystąpień
using BinsVector = std::vector<std::pair<int, int>>;

class Histogram
{
public:
	// zamiast:
    //Histogram();
    //Histogram(const std::vector<int>& values);
	// dwa w jednym:
    Histogram(const std::vector<int>& data = std::vector<int>());
    
	void emplace(int v);
    void emplace(const std::vector<int> &data);
    void clear();

    std::pair<int, int> max() const;
    std::pair<int, int> range() const;
	std::vector<int> unique_bins() const;
	std::vector<std::pair<int, int>> unique_items() const;
	
	Histogram& operator<<(int v);
	int operator[](int v) const; // zwraca częstość dla binu w indeksie
	// konwersja typów:
    operator BinsVector(); // operator konwersji na typ `BinsVector` (`std::vector<std::pair<int, int>>`)
	// tożsame z:
    // operator std::vector<std::pair<int, int>>();

	bool from_csv(const std::string &filename, char delim = ',', int column_idx = 4);
    
    friend std::istream &operator>>(std::istream &str, Histogram &hist);
    friend std::ostream &operator<<(std::ostream &str, const Histogram &hist);

    static Histogram rand(int min, int max, int count);
    static Histogram generate(int min, int max, int count);
    static Histogram generate(int count, int (*func_ptr)());
	
private:
    std::map<int, int> bins_;
};

void print(const std::vector<std::pair<int, int>> &bv);
