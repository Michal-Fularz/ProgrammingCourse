#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>



#include <list>

struct SStudenciZPI2013
{
	char pierwszaLiteraImienia;
	char pierwszaLiterazNaziwska;
	int indeks;
	double ocenaZPI;
};

void zad_1_prepare(void)
{
	FILE * pFile;
	fopen_s(&pFile, "studenciPI2013.txt", "w");
	if (pFile != NULL)
	{
		for (int i = 0; i < 2; ++i)
		{

		}

		fclose(pFile);
	}
}

void zad_1(void)
{
	FILE * pFile;
	fopen_s(&pFile, "studenciPI2013.txt", "r");
	if (pFile != NULL)
	{
		fscanf_s(pFile, "Oceny z PI w roku 2012 2013:\r\n");
		for (int i = 0; i < 12; ++i)
		{
			SStudenciZPI2013 nowyStudent;
			nowyStudent.pierwszaLiteraImienia = 'x';
			nowyStudent.pierwszaLiterazNaziwska = 'x';

			SStudenciZPI2013 st;

			fscanf_s(pFile, "Student %c. %c.; %d; %lf", &st.pierwszaLiteraImienia,
				&st.pierwszaLiterazNaziwska,
				&st.indeks,
				&st.ocenaZPI);

			printf("Student %c. %c.; %d; %1f\n", st.pierwszaLiteraImienia,
				st.pierwszaLiterazNaziwska,
				st.indeks,
				st.ocenaZPI);


			////int successes = fscanf_s(pFile, "Student %c.%c. ", &nowyStudent.pierwszaLiteraImienia, &nowyStudent.pierwszaLiterazNaziwska);
			////cout << successes << "\t";
			//fscanf_s(pFile, "Student %c. ", &nowyStudent.pierwszaLiteraImienia);
			//fscanf_s(pFile, "%c", &nowyStudent.pierwszaLiterazNaziwska);


			//fscanf_s(pFile, ". ; %d; %lf\n", &nowyStudent.indeks, &nowyStudent.ocenaZPI);

			////fscanf_s(pFile, "Student %c. %c.; %d; %lf\r\n", &nowyStudent.pierwszaLiteraImienia, &nowyStudent.pierwszaLiterazNaziwska, &nowyStudent.indeks, &nowyStudent.ocenaZPI);

			//cout << nowyStudent.pierwszaLiteraImienia << nowyStudent.pierwszaLiterazNaziwska << ": ";
			//cout << nowyStudent.indeks << ", " << nowyStudent.ocenaZPI << endl;
		}
		cout << endl;
		fclose(pFile);
	}
}

struct SKsiazka
{
	char tytul[20];
	int liczbaStron;
	int rokWydania;
	SKsiazka* nastepna;
};

SKsiazka *pierwsza;
SKsiazka *ostatnia;

void pokazKsiazke(SKsiazka *ksiazka)
{
	cout << "Ksiazka pt.: \"" << ksiazka->tytul << "\", liczba stron: " << ksiazka->liczbaStron << ", wydana w roku: " << ksiazka->rokWydania << endl;
}

void ustawKsiazke(SKsiazka *ksiazka, char tytul[20], int liczbaStron, int rokWydania)
{
	strcpy(ksiazka->tytul, tytul);
	ksiazka->liczbaStron = liczbaStron;
	ksiazka->rokWydania = rokWydania;
	ksiazka->nastepna = NULL;
}

bool czyGruba(SKsiazka *ksiazka)
{
	if (ksiazka->liczbaStron > 500)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void initKolejka()
{
	pierwsza = NULL;
	ostatnia = NULL;
}

void wlozKsiazke(SKsiazka *ksiazka)
{
	if (pierwsza != NULL)
	{
		ostatnia->nastepna = ksiazka;
		ostatnia = ksiazka;
	}
	else
	{
		pierwsza = ksiazka;
		ostatnia = ksiazka;
	}
}

SKsiazka* pobierzKsiazke()
{
	// sprawdzenie czy kolejka nie jest pusta
	if (pierwsza != NULL)
	{
		// pobranie do tymczasowej zmiennej pierwszego elementu (zwacanego)
		SKsiazka* tymczasowa = pierwsza;
		// nie ma wi�cej element�w
		if (pierwsza->nastepna == NULL)
		{
			pierwsza = NULL;
			ostatnia = NULL;
		}
		else
		{
			pierwsza = pierwsza->nastepna;
		}

		return tymczasowa;
	}
	else
	{
		return NULL;
	}
}

void zad_6(void)
{
	char tytul[20];
	int liczbaStron;
	int rokWydania;
	SKsiazka* ksiazka;
	for (int i = 0; i<3; i++)
	{
		cout << "Podaj tytul:\t";
		cin >> tytul;
		cout << "Liczba stron:\t";
		cin >> liczbaStron;
		cout << "Rok wydania:\t";
		cin >> rokWydania;
		ksiazka = new SKsiazka;
		ustawKsiazke(ksiazka, tytul, liczbaStron, rokWydania);
		if (czyGruba(ksiazka))
		{
			wlozKsiazke(ksiazka);
		}
	}

	for (int i = 0; i<3; i++)
	{
		ksiazka = pobierzKsiazke();
		if (ksiazka != NULL)
		{
			pokazKsiazke(ksiazka);
			delete ksiazka;
		}
	}
}







// how to use specialized constructor from default, available only for C++0x
class Foo
{
private:
	int value;

public:
	Foo()
	{
		value = 0;
	}

	Foo(int valueToSet) : Foo()
	{

	}


};

#include <iostream>

#include <conio.h>
#include <Windows.h>
static void TEST_beep(void)
{
	char odczytanyZnak = '1';

	while (odczytanyZnak != 'q')
	{
		for (int i = 0; i<20; ++i)
		{
			std::cout << '\a';
			Sleep(10);
		}
		odczytanyZnak = _getch();

		std::cout << "hahaha" << std::endl;
	}
}

using namespace std;

void Lab_1(void)
{
	printf("Hello world z printf!\r\n");
	cout << "Hello world z cout!" << endl;

	// zadeklarowa� zmienn� typu int
	int wczytywanaLiczba;
	int liczbaZwiekszona;	// o 5
	int liczbaZmniejszona;	// o 10
	// wczyta� przy pomocy cin
	cout << "Podaj wartosc liczbowa" << endl;
	cin >> wczytywanaLiczba;
	// operacja dodawania
	//liczbaZwiekszona
	// operacja odejmowania
	//liczbaZmniejszona
	// wy�wietli� za pomoc� cout
	cout << "Podales wartosc: \t" << wczytywanaLiczba << endl;
	//cout << "Wartosc zmniejszona: \t" << liczbaZmniejszona << endl;
	//cout << "Wartosc zwiekszona: \t" << liczbaZwiekszona << endl;

	printf("Liczba jako d: %d\r\n", wczytywanaLiczba);
	printf("Liczba jako c: %c\r\n", wczytywanaLiczba);
	printf("Liczba jako x: %x\r\n", wczytywanaLiczba);
	printf("Liczba jako f: %f\r\n", wczytywanaLiczba);

	system("pause");
}

void Lab_1_printf(void)
{
	printf("Hello world z printf!\r\n");
	cout << "Hello world z cout!" << endl;

	int wczytywanaLiczba;
	cout << "Podaje liczbe (cin): " << endl;
	cin >> wczytywanaLiczba;
	cout << "Podano liczbe: \t" << wczytywanaLiczba << endl;
	printf("Podaj liczbe (scanf): \r\n");
	scanf("%d", &wczytywanaLiczba);
	printf("Podano liczbe: \t%d\r\n", wczytywanaLiczba);

	system("pause");
}

typedef unsigned char u8;

u8 reverseByte(u8 data)
{
	u8 result = 0x00;

	// switch bits
	u8 k;
	for (k = 0; k<8; k++)
	{
		if ((data & (1 << k)) != 0)
		{
			result |= (1 << (7 - k));
		}
	}

	return result;
}

void TEST_reversByte(void)
{
	u8 data = 0x80;
	printf("%x, %x\r\n", data, reverseByte(data));
	data = 0xF0;
	printf("%x, %x\r\n", data, reverseByte(data));
	data = 0x02;
	printf("%x, %x\r\n", data, reverseByte(data));
	data = 0xA0;
	printf("%x, %x\r\n", data, reverseByte(data));

	scanf("%d", &data);
}

#define abc "abc"
#define countof(a)   (sizeof(a) / sizeof(*(a)))

#define VERSION_MAIN	"1.0"

// http://www.velocityreviews.com/forums/t316565-convert-__date__-to-unsigned-int.html
#define YEAR ( ( \
	((__DATE__[7] - '0') * 10 + \
	(__DATE__[8] - '0')) * 10 + \
	(__DATE__[9] - '0')) * 10 + \
	(__DATE__[10] - '0')		 \
	)

// UWAGA - �le wyznacza miesi�c np. January i June daj� to samo :/
// January | February | March | April | May | June | July | August | September | October | November | December
#define __MONTH_AS_NUMBER__ (  \
	__DATE__[2] == 'n' ? "01" : \
	__DATE__[2] == 'b' ? "02" : \
	__DATE__[2] == 'r' ? "03" : \
	__DATE__[0] == 'A' ? "04" : \
	__DATE__[0] == 'M' ? "05" : \
	__DATE__[0] == 'J' ? "06" : \
	__DATE__[2] == 'l' ? "07" : \
	__DATE__[2] == 'g' ? "08" : \
	__DATE__[2] == 'p' ? "09" : \
	__DATE__[2] == 't' ? "10" : \
	__DATE__[2] == 'v' ? "11" : \
	"12"   \
	)

#define MONTH (  \
	__DATE__[2] == 'n' ? 0 : \
	__DATE__[2] == 'b' ? 1 : \
	__DATE__[2] == 'r' ? 2 : \
	__DATE__[0] == 'A' ? 3 : \
	__DATE__[0] == 'M' ? 4 : \
	__DATE__[0] == 'J' ? 5 : \
	__DATE__[2] == 'l' ? 6 : \
	__DATE__[2] == 'g' ? 7 : \
	__DATE__[2] == 'p' ? 8 : \
	__DATE__[2] == 't' ? 9 : \
	__DATE__[2] == 'v' ? 10 : \
	11		\
	)

#define DAY (	\
	(__DATE__[4] == ' ' ? 0 : \
	__DATE__[4] - '0') * 10	\
	+ (__DATE__[5] - '0')		\
	)

#define DATE_AS_INT (((YEAR - 2000) * 356 + MONTH) * 31 + DAY)

// http://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html#Argument-Prescan
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define VERSION_COMPLETE ( \
	VERSION_MAIN		\
	"."					\
	TOSTRING(YEAR)		\
	)

void TEST_define(void)
{
	printf("%s\r\n", abc);
	printf("time: %s, date: %s, month as number: %s\r\n", __TIME__, __DATE__, __MONTH_AS_NUMBER__);
	printf("Year: %d\r\n", YEAR);
	printf("Version: %s\r\n", VERSION_COMPLETE);

	printf("%d-%02d-%02d = %d\n", YEAR, MONTH + 1, DAY, DATE_AS_INT);

	for (int i = 0; i<sizeof(__TIME__); i++)
	{
		printf("%c", __TIME__[i]);
	}
	printf("\r\n");

	for (int i = 0; i<sizeof(__DATE__); i++)
	{
		printf("%c", __DATE__[i]);
	}
	printf("\r\n");

	for (int i = 0; i<sizeof(abc); i++)
	{
		printf("%c", abc[i]);
	}
	printf("\r\n");
}

#include <vector>
void Vector_TestOutOfRange(void)
{
	vector<int> v(10);

	int val;

	try
	{
		val = v.at(v.size() + 10);
	}
	catch (std::out_of_range& ex)
	{
		std::cout << "\nOut of range exception caught.\n" << ex.what() << std::endl;
	}

	val = v[v.size() + 10];
}

#include <time.h>

void Vector_TestInsert(void)
{
	clock_t start, stop;
	float czasOperacji;

	vector<int> v(5000000);

	start = clock();

	// operacje do wykonania
	v.push_back(5);

	stop = clock();
	czasOperacji = (float)(stop - start) / (CLOCKS_PER_SEC);
	cout << "Czas wykonywania push_back: " << czasOperacji << endl;

	start = clock();

	// operacje do wykonania
	v.insert(v.begin(), 5);

	stop = clock();
	czasOperacji = (float)(stop - start) / (CLOCKS_PER_SEC);
	cout << "Czas wykonywania insert: " << czasOperacji << endl;

	start = clock();

	// operacje do wykonania
	v.push_back(5);

	stop = clock();
	czasOperacji = (float)(stop - start) / (CLOCKS_PER_SEC);
	cout << "Czas wykonywania push_back: " << czasOperacji << endl;
}

bool sortuj(int a, int b)
{
	bool result;

	if (b>a)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

#include <stdio.h>
void File_readMultipleStructures()
{
	FILE* file;
	file = fopen("data.txt", "r");

	if (file != NULL)
	{
		int valueDecimal;
		float valueFloatingpoint;

		while (fscanf(file, "%d, %f\n", &valueDecimal, &valueFloatingpoint) != EOF)
		{
			cout << valueDecimal << ", " << valueFloatingpoint << endl;
		}
		fclose(file);
	}
}

struct s1
{
	int value;
};

struct punkt
{
	char adres[10];
	char nazwa[10];
	int numer;
};

#include <list>
void Pytanie_IteratoryWListach(void)
{
	int nowy;
	list<int> lista;
	list<int>::iterator itr;

	std::cin >> nowy;

	lista.push_back(nowy);
	itr = lista.end();

	//punkt temp;
	int temp;
	temp = *itr;
	//cout<<temp.numer;
	cout << temp;
}

void TEST_vecroty_listy(void)
{
	Pytanie_IteratoryWListach();

	list<s1> l;

	for (auto itr = l.begin(); itr != l.end(); ++itr)
	{
		itr->value;
		(*itr).value;
	}

	File_readMultipleStructures();


	//Vector_TestOutOfRange();
	Vector_TestInsert();

	list<int> l1;

	l1.push_back(6);
	l1.push_back(5);
	l1.push_back(4);
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);

	list<int>::iterator itL;

	for (itL = l1.begin(); itL != l1.end(); ++itL)
	{
		cout << *itL << ", ";

		*itL = *itL + 1;
	}
	cout << endl;

	itL = l1.begin();
	for (int i = 0; i<l1.size(); ++i)
	{
		if (i == 3)
		{
			itL = l1.erase(itL);
		}

		itL++;
	}

	//l1.erase(l1.begin() + 3);

	l1.sort(sortuj);

	for (itL = l1.begin(); itL != l1.end(); ++itL)
	{
		cout << *itL << ", ";
	}
	cout << endl;

	system("pause");

	vector<int> v1;
	for (int i = 1; i<7; ++i)
	{
		v1.push_back(i);
	}
	vector<int>::iterator itV;
	for (itV = v1.begin(); itV != v1.end(); itV++)
	{
		cout << *itV << ", ";
	}
	cout << endl;

	v1.erase(v1.begin() + 3);

	cout << *(v1.begin() + 3) << endl;

	for (itV = v1.begin(); itV != v1.end(); itV++)
	{
		cout << *itV << ", ";
	}
	cout << endl;

	system("pause");
}

#include <stack>
#include <queue>

struct test
{
	int a;
	int b;
};

static void testQueueStack(void)
{
	int value;

	std::stack<int> stos;
	stos.empty();
	stos.push(5);
	stos.size();
	value = stos.top();
	stos.pop();

	test valueTest;

	std::queue<test> kolejka;
	kolejka.empty();
	kolejka.push(valueTest);
	kolejka.size();
	valueTest = kolejka.front();
	valueTest = kolejka.back();
	kolejka.pop();
}

#if 0
	static void dynamicTableTest(void)
	{
		int rozmiar;
		cin >> rozmiar;
		int tab[rozmiar];

		for (int i = 0; i<rozmiar; i++)
		{
			cin >> tab[i];
		}

		for (int i = 0; i<rozmiar; i++)
		{
			std::cout << tab[i] << std::endl;
		}
	}
#endif

	typedef unsigned char	uint8_t;
	typedef	unsigned short	uint16_t;
	typedef unsigned int	uint32_t;

	typedef uint16_t		used_type_t;

#define NUMBER_OF_BITS_TO_COUNT				256
#if (used_type_t == uint8_t)
#define NUMBER_OF_BITS_IN_ONE_VARIABLE		8
#endif
#define NUMBER_OF_VARIABLES					(NUMBER_OF_BITS_TO_COUNT/NUMBER_OF_BITS_IN_ONE_VARIABLE)

uint16_t count_ones(used_type_t values[NUMBER_OF_VARIABLES])
{
	uint16_t numberOfOnes = 0;
	uint8_t i, j;


	count_ones_label0:for (i = 0; i<NUMBER_OF_VARIABLES; i++)
	{

		count_ones_label1:for (j = 0; j<NUMBER_OF_BITS_IN_ONE_VARIABLE; j++)
		{
			//if((values[i] & (1<<j)) == (1<<j))
			// �le - & ma ni�szy priorytet ni� ==, co ciekawe + ma wy�szy
			if (values[i] & (1 << j) == (1 << j))
				// �le - jak wy�ej
				//if(values[i] & (1<<j) != 0)
			{
				numberOfOnes++;
			}
		}
	}

	return numberOfOnes;
}

int testCountOnes()
{
	used_type_t inputArgument[NUMBER_OF_VARIABLES] = { 2, 4, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 2, 1, 1 };

	uint16_t outputValue = count_ones(inputArgument);

	int retval;

	if (outputValue == 16)
	{
		retval = 0;
		printf("Test passed !\n");
	}
	else
	{
		retval = 1;
		printf("Test failed  !!!\n");
	}

	// Return 0 if the test
	return retval;
}

struct SZespolone
{
	int re;
	int im;

	friend ostream& operator<<(ostream& os, const SZespolone z);
};

ostream& operator<<(ostream& os, const SZespolone z)
{
	os << z.re << ' ' << z.im << '\n';
	return os;
}

static inline void TestOstreamOverloadedOperator(void)
{
	SZespolone z;
	z.re = 5;
	z.im = 3;

	std::cout << z;
}


int main(void)
{

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync();		// Flush The Input Buffer Just In Case
	std::cin.ignore();		// There's No Need To Actually Store The Users Input

	return 1;
}


class pasazer{
public:
	//dane:
	string imie;
	string nazwisko;
	unsigned int masa;
	unsigned int masa_bagazu;

	//funkcje sk�adowe:
	void wypisz();
	unsigned int MasaCalkowita();

	//konstruktor:
	pasazer(unsigned int K_masa = 0,
		unsigned int K_masa_bagazu = 0,
		string K_imie = "Brak",
		string K_nazwisko = "");

	~pasazer(void);
};


pasazer::pasazer(unsigned int K_masa,
	unsigned int K_masa_bagazu,
	string K_imie,
	string K_nazwisko) :
	masa(K_masa), masa_bagazu(K_masa_bagazu), imie(K_imie), nazwisko(K_nazwisko)
{

	cout << "\nPasazer " << imie << " " << nazwisko << " wszedl na poklad\n";
}

pasazer::~pasazer(void){
	cout << "\nPasazer " << imie << " " << nazwisko << " oposcil poklad\n";
	system("pause");
}



class DC3{
	//Dane:
private:
	//Dane niezmienne dla typu samolotu:
	const unsigned long masa_wlasna = 8300;//kg
	static bool dopuszczony;

	//Dane zale�ne od konfiguracji
	unsigned int pojemnosc;//pasa�er�w
	double zuzycie_paliwa;//ton/1000km
	unsigned long paliwo;//kg
	unsigned long masa_startowa;//kg
	pasazer *lista;//lista pasa�er�w
public:
	string nazwa;

	//Metody:
private:
	void licz_mase(unsigned long km);//oblicza mas� startow� na zadanej trasie
	void wydruk(ostream& strumien);
public:
	void manifest(unsigned long jak_daleko);
	bool dodaj_pasazera(pasazer);
	bool usun_pasazera(int nr);//0=usu� wszystkich

	static void zezwolenie(bool z);//funkcja statyczna
	//Konstruktor:
	DC3(string K_nazwa = "Zwykly DC3", unsigned int K_pojemnosc = 32, double K_zuzycie_paliwa = 1.5);
	//Dostruktor:
	//~DC3(void);
};

DC3::DC3(
	string K_nazwa,
	unsigned int K_pojemnosc,
	double K_zuzycie_paliwa)
{
	pojemnosc = K_pojemnosc;//pasa�er�w
	zuzycie_paliwa = K_zuzycie_paliwa;//ton/1000km
	nazwa = K_nazwa;

	lista = new pasazer[pojemnosc];//lista pasa�er�w
	pasazer pom(0, 0, "", "");
	for (unsigned int i = 0; i<pojemnosc; i++){ lista[0] = pom; }
}

#include <list>
#include <vector>

struct osoba
{
	string imie;
	string nazwisko;
};

int Rafa�_code_test_main(void)
{
	list<osoba> osoby;

	{
		osoba nowaOsoba;
		nowaOsoba.imie = "aaa";
		nowaOsoba.nazwisko = "bbb";
		osoby.push_back(nowaOsoba);
	}

	for (auto itr = osoby.begin(); itr != osoby.end(); itr++)
	{
		std::cout << "osoba: " << itr->imie << endl;
	}

	{
		vector<pasazer> pasazery;

		{


			pasazer nowy_pasazer(99, 19, "asdkja", "kasdj");

			pasazery.push_back(nowy_pasazer);

			//pasazery.push_back(new pasazer(567,21, "dasdas", "asdasd"));
		}

		for (auto itr = pasazery.begin(); itr != pasazery.end(); itr++)
		{
			std::cout << "pasazer: " << itr->masa << endl;
		}

		pasazery[0].imie = "asdfewquryhweiurhwiuwerh";
		std::cout << "pasazer: " << pasazery[0].masa << endl;
	}


	DC3 plane;

	int k = k + 1;

	std::cout << k << endl;

	return 0;
}