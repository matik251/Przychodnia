#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Widok.h"

using namespace std;

std::string  szyfruj(std::string s);
std::string  deszyfruj(std::string s);

struct Osoba {
	int id;
	std::string imie;
	std::string nazwisko;
	std::string plec;
	int dataUrodzenia;
	std::string  PESEL;
	int wzrost;
	int waga;
	Osoba *nastepny;
public:
	Osoba() : id(0), imie("NA"), nazwisko("NA"), plec("NA"), dataUrodzenia(0), PESEL("NA"), wzrost(0), waga(0), nastepny(nullptr) {};
	Osoba(const Osoba &osoba) : id(osoba.id), imie(osoba.imie), nazwisko(osoba.nazwisko), plec(osoba.plec), dataUrodzenia(osoba.dataUrodzenia), PESEL(osoba.PESEL), wzrost(osoba.wzrost), waga(osoba.waga) {};
	Osoba& operator=(Osoba&& object);
	void wypiszOsobe(Osoba* osoba);
};

struct Wizyta {
	int id;
	std::string PESEL;
	std::string Lekarz;
	int data;
	int godzina;
	std::string wynik;
	Wizyta* nastepna;
};

class Pacjenci {
private:
	Osoba* head;
	int size;

public:
	void addPacjent();
	void addPacjent(Osoba* osoba);
	void removePacjent(std::string PESEL);
	int getSize();
	Pacjenci() : head(nullptr), size(0) {};
	Pacjenci(const Pacjenci &lista) : head(lista.head), size(lista.size) {};
	bool czyJestPesel(const Osoba* osoba);
	bool czyJestPeselNr(const std::string PESEL);
	Osoba* znajdzPacjenta(const std::string PESEL);
	~Pacjenci();
	void wczytajListe();
	void wypiszListe();
	void zapiszListe();
	Osoba* pobierzDaneOsobowe();

};

class Terminarz
{
private:
	Wizyta* head;
	int size;

public:
	void addWizyta();
	void addWizyta(Wizyta* wizyta);
	void removeWizyta(std::string PESEL, int data, int godzina);
	int getSize();

	class Terminarz() : head(nullptr), size(0) {};
	Wizyta* znajdzWizyte(const std::string PESEL, int data, int godzin);
	bool czyWolnyTermin(int data, int godzin, std::string Lekarz);
	~Terminarz();
	void wczytajListe();
	void wypiszListe();
	void zapiszListe();
	Wizyta* pobierzDane();

};
