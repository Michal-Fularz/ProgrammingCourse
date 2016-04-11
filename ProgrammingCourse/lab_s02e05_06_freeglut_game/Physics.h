#pragma once

#include "Figure.h"

namespace MF
{
	typedef struct Border
	{
		double xa; //minimalna wartosc x
		double ya; //minimalna wartosc y
		double xb; //maskymalna wartosc x
		double yb; //maskymalna wartosc y
	} Border;/*granice okreslaja lewy gorny naroznik (xa,ya) i prawy dolny (xb,yb) */


	class Physics : public Figure
	{
	protected:
		int m_czas; //czas ostatniej aktualizacji
		Border m_granica; //granice obiektu
		//polozenie srodka masy - odziedziczone po Figure
		double m_v;//predkosc
		double m_alfa_v;//kierunek wektora predkosci w [stopniach]
		double m_g; //grawitacja
		double m_alfa_g;//kierunek wektora grawitacji

	public:
		Physics();
		~Physics();
		void Aktualizuj(int czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
		void UstawCzas(int czas_aktualny);
		void UstawPredkosc(double _v, double _m_alfa_v); //ustawia poczatkowa predkosc
		void UstawFizyke(double _g, double _m_alfa_g); //ustawia poczatkowe przyspieszenie
		void UstawGeometrie(double _x, double _y, double _xa, double _ya, double _xb, double _yb);
		virtual int Kolizja(const Physics& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)

	private:
		void Odbicie(double alfa_n); //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
		int WProstokacie(double _x, double _y, const Physics& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego prostok¹ta
		double Odleglosc(double _x, double _y, double _xa, double _ya, double _xb, double _yb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
		virtual double ZnajdzNormalna(const Physics& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
	};

}
