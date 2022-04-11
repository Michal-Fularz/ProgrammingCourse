#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <histogram.h>

int main()
{
    std::cout << "Hello lab06!" << std::endl;

    Histogram hist; //Konstruktor domyślny

    Histogram hist_2(std::vector<int>({10,15,6,9,10,12})); // definiuje obiekt wywołując konstruktor inicjujący go listą wyników w punktach


    hist.emplace(20); //dodaje ocenę 20pkt

    hist.emplace(std::vector<int>({10, 15, 6, 9, 10, 12}));

    hist << 10 << 12 << 20 << 21; // kolejne elementy zawierają punktację poszczególnych studentów
	
	// tożsame wywołania:
	(hist << 10);
    hist.operator<<(10);

    std::cin >> hist; // pobiera dane od użytkownika (pobierając najpierw liczbę wyników, które chce wprowadzić)

    hist.from_csv(R"(../wyniki.csv)", ',', 4); //wczytuje plik csv, argumentami są nazwa pliku, separator kolumn oraz index kolumny w której znajdują się dane dla histogramu

    hist_2.clear(); //usuwa wszystkie dane z histogramu // jeśli dane nie zostaną usunięte kolejne wywołania operatora zapisu do strumienia lub


    std::cout << hist; // zapis histogramu do strumienia tekstowego

    std::ofstream file("histogram.txt");
    if (file.is_open())
    {
        file << hist; // zapis histogramu do pliku (identycznie jak dla wyświetlenia go na konsoli)
    }
    file.close();

    int freq = hist[10]; // zwraca częstość dla przedziału do którego należy wartość 10.5
	std::cout << "freq value 10: " << hist[10] << std::endl;

    std::pair<Bin, Bin> range = hist.range(); // zwraca początkowy i końcowy przedział.

    std::pair<Bin, Frequency> max = hist.max(); // zwraca najczęściej występujący przedział oraz jego częstość

    std::vector<Bin> bins = hist.unique_bins(); // zwraca listę unikalnych, niepustych przedziałów
                                                // (gdzie dla przedziału o szerokości 5 i wartości
                                                // elementu 0 jest przedziałem [0-5), 5 -> [5,10), itp.]

    std::vector<std::pair<Bin, Frequency>> items = hist.unique_items(); // zwraca listę niepustych przedziałów oraz częstość wystąpień

    //konwersja na inne typy
    using BinsVector = std::vector<std::pair<Bin, Frequency>>;
    BinsVector items_vect = static_cast<BinsVector>(hist); // operator rzutowania działa tak samo jak  Histogram::unique_items
    print(items_vect); // zewnętrzna funkcja wyświetlająca wektor elementów histogramu

    Histogram hist_3_1 = Histogram::generate(-10, 10, 100); // tworzy histogram zawierający wartości losowe, gdzie kolejne argumenty oznaczają wartość minimalną, maksymalną, liczbę elementów
    Histogram hist_3_2 = Histogram::generate(100, [](){ return -10 + rand() % 21; }); // tworzy histogram zawierający wartości losowe,  liczbę elementów do losowania oraz wskaźnik do funkcji losującej pojedynczy element

    return 0;
}
