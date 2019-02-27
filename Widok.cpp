#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include "Listy.h"
#include "Widok.h"

char Widok::pobierzInput()
{
	return this->wybor;
}

void Widok::ustawInputJako(char input)
{
	this->wybor = input;
}

void Widok::menuGlowne()
{
	system("CLS");
	std::cout << "1. Zaladuj baze" << std::endl;
	std::cout << "2. Rejestracja" << std::endl;
	std::cout << "3. Lekarz" << std::endl;
	std::cout << "4. Wypisz baze pacjentow" << std::endl;
	std::cout << "5. Zapisz baze" << std::endl;
	std::cout << "6. Zamknij" << std::endl;
	std::cin >> this->wybor;
}

void Widok::widokRejestracja()
{
	system("CLS");
	std::cout << "1. Dodaj pacjenta" << std::endl;
	std::cout << "2. Usuna pacjenta" << std::endl;
	std::cout << "3. Umow wizyte" << std::endl;
	std::cout << "6. Zakoncz" << std::endl;
	std::cin >> this->wybor;
}

void Widok::widokLekarza()
{
	system("CLS");
}

std::string Widok::pobierzPesel() 
{
	std::string pesel;
	system("CLS");
	std::cout << "Podaj PESEL: ";
	std::cin >> pesel;
	return pesel;
}

int Widok::pobierzInt(std::string tekst)
{
	int liczba;
	system("CLS");
	std::cout << "tekst: ";
	std::cin >> liczba;
	return liczba;
}

std::string Widok::pobierzString(std::string tekst)
{
	std::string tekst2;
	system("CLS");
	std::cout << "tekst: ";
	std::cin >> tekst2;
	return tekst2;
}

