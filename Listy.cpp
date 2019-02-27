#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Listy.h"

using namespace std;

std::string szyfruj(std::string s)
{
	for (int i = 0; i < s.length(); i++) {
		s[i] = s[i] + 3;
	}
}

std::string  deszyfruj(std::string s)
{
	for (int i = 0; i < s.length(); i++) {
		s[i] = s[i] - 3;
	}
}

Osoba* Pacjenci::pobierzDaneOsobowe()
{

	system("CLS");
	Osoba* nowaOsoba = new Osoba;
	string temp;

	std::cout << "Imie: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaOsoba->imie);
	std::cout << "Nazwisko: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaOsoba->nazwisko);
	std::cout << "Plec (k/m): " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaOsoba->plec);
	std::cout << "Data Urodzenia (RRRRMMDD): " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, temp);
	nowaOsoba->dataUrodzenia = stoi(temp);
	std::cout << "PESEL: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaOsoba->PESEL);
	std::cout << "Wzrost: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, temp);
	nowaOsoba->wzrost = stoi(temp);
	std::cout << "Waga: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, temp);
	nowaOsoba->waga = stoi(temp);
	return nowaOsoba;
}

void Osoba::wypiszOsobe(Osoba * osoba)
{
	system("CLS");
	std::cout << "Imie: " << osoba->imie << std::endl;
	std::cout << "Nazwisko: " << osoba->nazwisko << std::endl;
	std::cout << "Plec: " << osoba->plec << std::endl;
	std::cout << "Data urodzenia: " << (osoba->dataUrodzenia % 10000) << "-" << osoba->dataUrodzenia % 100 - (osoba->dataUrodzenia % 10000) << "-" << osoba->dataUrodzenia - (osoba->dataUrodzenia % 100) << std::endl;
	std::cout << "PESEL: " << osoba->PESEL << std::endl;
	std::cout << "Wzrost: " << osoba->wzrost << std::endl;
	std::cout << "Waga: " << osoba->waga << std::endl << std::endl;
}

void Pacjenci::addPacjent()
{
	Osoba* nowaOsoba = pobierzDaneOsobowe();

	if (!this->czyJestPesel(nowaOsoba)) {
		this->size++;
		nowaOsoba->id = size;
		if (this->head == nullptr)
			this->head = nowaOsoba;

		else {
			Osoba *listHead = this->head;

			while (listHead->nastepny != nullptr)
				listHead = listHead->nastepny;

			listHead->nastepny = nowaOsoba;
			listHead->nastepny->nastepny = nullptr;
		}
	}
	else {
		std::cout << "Osoba o danym PESELU juz jest w systemie!" << std::endl;
		delete nowaOsoba;
	}
	return;
}

void Pacjenci::addPacjent(Osoba* nowaOsoba)
{
	if (!this->czyJestPesel(nowaOsoba)) {
		this->size++;
		nowaOsoba->id = size;
		if (this->head == nullptr)
			this->head = nowaOsoba;
		else {
			Osoba *listHead = this->head;

			while (listHead->nastepny != nullptr)
				listHead = listHead->nastepny;

			listHead->nastepny = nowaOsoba;
			listHead->nastepny->nastepny = nullptr;
		}
	}
	else {
		std::cout << "Osoba o danym PESELU juz jest w systemie!" << std::endl;
		delete nowaOsoba;
	}
	return;
}

bool Pacjenci::czyJestPesel(const Osoba* osoba)
{
	Osoba *temp = this->head;

	while (temp != nullptr) {
		if (temp->PESEL == osoba->PESEL)
			return true;
		temp = temp->nastepny;
	}

	return false;
}

bool Pacjenci::czyJestPeselNr(const std::string PESEL)
{
	Osoba *temp = this->head;

	while (temp != nullptr) {
		if (temp->PESEL == PESEL)
			return true;
		temp = temp->nastepny;
	}
	return false;
}

Osoba* Pacjenci::znajdzPacjenta(const std::string PESEL)
{
	Osoba *temp = this->head;

	while (temp != nullptr) {
		if (temp->PESEL == PESEL)
			return temp;
		temp = temp->nastepny;
	}
	return nullptr;
}

Pacjenci::~Pacjenci()
{
	if (this->head != nullptr) {
		Osoba *deleter = this->head;

		if (deleter->nastepny == nullptr)
			delete deleter;

		else {
			while (deleter->nastepny != nullptr) {
				deleter = deleter->nastepny;
				delete this->head;
				this->head = deleter;
			}
			delete deleter;
		}
	}
}

inline void Pacjenci::wczytajListe()
{
	Osoba* nowaOsoba = new Osoba;
	string s, id, imie, nazwisko, plec, dataUr, PESEL, wzrost, waga;
	int srednik;
	fstream plik;
	plik.open("lekarze.csv", ios::in);
	while (!plik.eof()) {
		plik >> s;
		srednik = s.find(";");
		id = s.substr(0, srednik);
		imie = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		nazwisko = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		plec = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		dataUr = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		PESEL = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		wzrost = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		waga = s.substr(srednik + 1, s.length() - srednik);
		/*cout << id << " "
		<< imie << " "
		<< nazwisko << " "
		<< plec << " "
		<< dataUr << " "
		<< PESEL << " "
		<< wzrost << " "
		<< waga << endl;*/
		nowaOsoba->imie = imie;
		nowaOsoba->nazwisko = nazwisko;
		nowaOsoba->plec = plec;
		nowaOsoba->dataUrodzenia = stoi(dataUr);
		nowaOsoba->PESEL = PESEL;
		nowaOsoba->waga = stoi(waga);
		nowaOsoba->wzrost = stoi(wzrost);
		addPacjent(nowaOsoba);
	}
}

inline void Pacjenci::wypiszListe()
{
	Osoba *temp = this->head;

	while (temp != nullptr) {

		system("CLS");
		std::cout << "Imie: " << temp->imie << std::endl;
		std::cout << "Nazwisko: " << temp->nazwisko << std::endl;
		std::cout << "Plec: " << temp->plec << std::endl;
		std::cout << "Data urodzenia: " << (temp->dataUrodzenia % 10000) << "-" << temp->dataUrodzenia % 100 - (temp->dataUrodzenia % 10000) << "-" << temp->dataUrodzenia - (temp->dataUrodzenia % 100) << std::endl;
		std::cout << "PESEL: " << temp->PESEL << std::endl;
		std::cout << "Wzrost: " << temp->wzrost << std::endl;
		std::cout << "Waga: " << temp->waga << std::endl << std::endl;
		temp = temp->nastepny;
	}

}

inline void Pacjenci::zapiszListe()
{
	Osoba *temp = this->head;

	fstream plik;
	plik.open("lekarze.csv", ios::out);
	while (temp != nullptr) {

		plik << temp->id << ";" << temp->nazwisko << ";" << temp->imie << ";" << temp->plec << ";" << temp->dataUrodzenia << ";" << temp->PESEL << ";" << temp->wzrost << ";" << temp->waga;
		if (temp->nastepny != nullptr) plik << "\n";
		temp = temp->nastepny;
	}

}

void Pacjenci::removePacjent(std::string PESEL)
{
	bool jest = czyJestPeselNr(PESEL);
	if (this->head == nullptr)
		std::cout << "Lista pacjentow jest pusta" << std::endl;

	else if (jest)
		std::cout << "Brak osoby w bazie" << std::endl;

	else if (jest)
	{
		Osoba *temp = this->head;
		Osoba *doUsiniecia = znajdzPacjenta(PESEL);
		if (temp == doUsiniecia) {
			delete temp;
			this->head = nullptr;
		}
		else {
			while (temp->nastepny == doUsiniecia) {
				temp = temp->nastepny;
			}
			temp->nastepny = doUsiniecia->nastepny;
			delete doUsiniecia;
		}
		this->size--;
	}
}

inline int Pacjenci::getSize()
{
	return this->size;
}

Osoba & Osoba::operator=(Osoba && object)
{
	this->id = std::move(object.id);
	this->imie = std::move(object.imie);
	this->nazwisko = std::move(object.nazwisko);
	this->plec = std::move(object.plec);
	this->dataUrodzenia = std::move(object.dataUrodzenia);
	this->PESEL = std::move(object.PESEL);
	this->wzrost = std::move(object.wzrost);
	this->waga = std::move(object.waga);

	return *this;
}

void Terminarz::addWizyta()
{
	Wizyta* nowaWizyta = new Wizyta;

	if (!this->czyWolnyTermin(nowaWizyta->data,nowaWizyta->godzina,nowaWizyta->Lekarz)) {
		this->size++;
		nowaWizyta->id = size;
		if (this->head == nullptr)
			this->head = nowaWizyta;

		else {
			Wizyta *listHead = this->head;

			while (listHead->nastepna != nullptr)
				listHead = listHead->nastepna;

			listHead->nastepna = nowaWizyta;
			listHead->nastepna->nastepna = nullptr;
		}
	}
	else {
		std::cout << "Termin jest zajety" << std::endl;
		delete nowaWizyta;
	}
	return;
}

void Terminarz::addWizyta(Wizyta * nowaWizyta)
{
	if (!this->czyWolnyTermin(nowaWizyta->data, nowaWizyta->godzina, nowaWizyta->Lekarz)) {
		this->size++;
		nowaWizyta->id = size;
		if (this->head == nullptr)
			this->head = nowaWizyta;

		else {
			Wizyta *listHead = this->head;

			while (listHead->nastepna != nullptr)
				listHead = listHead->nastepna;

			listHead->nastepna = nowaWizyta;
			listHead->nastepna->nastepna = nullptr;
		}
	}
	else {
		std::cout << "Termin jest zajety" << std::endl;
		delete nowaWizyta;
	}
	return;
}

void Terminarz::removeWizyta(std::string PESEL, int data, int godzina)
{
	Wizyta *temp = this->head;
	Wizyta *doUsiniecia = znajdzWizyte(PESEL,data,godzina);
	if (doUsiniecia)
	{
		if (temp == doUsiniecia) {
			delete temp;
			this->head = nullptr;
		}
		else {
			while (temp->nastepna == doUsiniecia) {
				temp = temp->nastepna;
			}
			temp->nastepna = doUsiniecia->nastepna;
			delete doUsiniecia;
		}
		this->size--;
	}
}

int Terminarz::getSize()
{
	return this->size;
}

Wizyta* Terminarz::znajdzWizyte(const std::string PESEL, int data, int godzin)
{
	Wizyta *temp = this->head;

	while (temp != nullptr) {
		if ((temp->PESEL == PESEL)&&(temp->data == data)&&(temp->godzina == godzin))
			return temp;
		temp = temp->nastepna;
	}
	return nullptr;
} 

bool Terminarz::czyWolnyTermin(int data, int godzin, std::string Lekarz)
{

	Wizyta *temp = this->head;

	while (temp != nullptr) {
		if ((temp->Lekarz == Lekarz) && (temp->data == data) && (temp->godzina == godzin))
			return false;
		temp = temp->nastepna;
	}
	return true;
}

Terminarz::~Terminarz()
{
	if (this->head != nullptr) {
		Wizyta *deleter = this->head;

		if (deleter->nastepna == nullptr)
			delete deleter;

		else {
			while (deleter->nastepna != nullptr) {
				deleter = deleter->nastepna;
				delete this->head;
				this->head = deleter;
			}
			delete deleter;
		}
	}
}

void Terminarz::wczytajListe()
{
	Wizyta* nowaWIzyta = new Wizyta;
	string s, id, data, godzina, PESEL, lekarz, wynik;
	int srednik;
	fstream plik;
	plik.open("wizyty.csv", ios::in);
	while (!plik.eof()) {
		plik >> s;
		srednik = s.find(";");
		id = s.substr(0, srednik);
		data = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		godzina = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		PESEL = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		lekarz = s.substr(srednik + 1, s.find(";", srednik + 1) - (srednik + 1));
		srednik = s.find(";", srednik + 1);
		wynik = s.substr(srednik + 1, s.length() - srednik);
		nowaWIzyta->id = stoi(id);
		nowaWIzyta->data = stoi(data);
		nowaWIzyta->godzina = stoi(godzina);
		nowaWIzyta->PESEL = PESEL;
		nowaWIzyta->Lekarz = lekarz;
		nowaWIzyta->wynik = wynik;
		addWizyta(nowaWIzyta);
	}
}

void Terminarz::wypiszListe()
{
	Wizyta *temp = this->head;

	while (temp != nullptr) {

		system("CLS");
		std::cout << "Data: " << (temp->data % 10000) << "-" << temp->data % 100 - (temp->data % 10000) << "-" << temp->data - (temp->data % 100) << std::endl;
		std::cout << "Godzina: " << temp->godzina % 100  << "-" << temp->godzina - (temp->godzina % 100)*100 << std::endl;
		std::cout << "PESEL: "  << temp->PESEL << std::endl;
		std::cout << "Lekarz: " << temp->Lekarz << std::endl;
		std::cout << "Wynik: " << temp->wynik << std::endl;
		temp = temp->nastepna;
	}
}

void Terminarz::zapiszListe()
{
	Wizyta *temp = this->head;

	fstream plik;
	plik.open("wizyty.csv", ios::out);
	while (temp != nullptr) {

		plik << temp->id << ";" << temp->data << ";" << temp->godzina << ";" << temp->PESEL << ";" << temp->Lekarz << ";" << temp->wynik;
		if (temp->nastepna != nullptr) plik << "\n";
		temp = temp->nastepna;
	}
}

Wizyta * Terminarz::pobierzDane()
{

	system("CLS");
	Wizyta* nowaWizyta = new Wizyta;
	string temp;

	std::cout << "Termin (RRRRMMDD): " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, temp);
	nowaWizyta->data = stoi(temp);
	std::cout << "Godzina (HHMM): " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, temp);
	nowaWizyta->godzina = stoi(temp);
	std::cout << "Pesel: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaWizyta->PESEL);
	std::cout << "Lekarz: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nowaWizyta->PESEL);

	return nowaWizyta;
}
