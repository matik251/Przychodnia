#include "stdafx.h"
#include "Rejestracja.h"
#include "Listy.h"
#include "Widok.h"
#include <Windows.h>


void Obsluga::przychodnia()
{

	Widok widok;
	Pacjenci pacjenci ;
	Terminarz terminarz;

	RejestracjaObsluga rejestracja;
	LekarzObsluga lekarz;
	do {
		widok.menuGlowne();
		switch (widok.pobierzInput()) {
		case '1': pacjenci.wczytajListe();terminarz.wczytajListe(); break;
		case '2': rejestracja.obslugaRejestracji(widok, pacjenci, terminarz); break;
		case '3': lekarz.obslugaLekarza(widok, pacjenci, terminarz); break;
		case '4': pacjenci.zapiszListe(); break;
		case '5': pacjenci.zapiszListe();terminarz.wczytajListe(); break;
		}
	} while (widok.pobierzInput() != '6');
}


void RejestracjaObsluga::obslugaRejestracji(Widok widok, Pacjenci pacjenci, Terminarz terminarz)
{
	do {
		widok.widokRejestracja();
		switch (widok.pobierzInput()) {
		case '1': dodajPacjenta(widok, pacjenci); break;
		case '2': usunPacjenta(widok, pacjenci); break;
		case '3': umowWizyte(widok, pacjenci, terminarz); break;
		}
	} while (widok.pobierzInput() != '4');
	return;
}

void RejestracjaObsluga::dodajPacjenta(Widok widok, Pacjenci pacjenci)
{
	pacjenci.addPacjent();
	//pacjenci.wypiszListe();
	system("PAUSE");
}

void RejestracjaObsluga::usunPacjenta(Widok widok, Pacjenci pacjenci)
{
	pacjenci.removePacjent(widok.pobierzPesel());
	//pacjenci.wypiszListe();
	system("PAUSE");
}

void RejestracjaObsluga::umowWizyte(Widok widok, Pacjenci pacjenci, Terminarz terminarz)
{
	terminarz.addWizyta();
	system("PAUSE");
}


void LekarzObsluga::obslugaLekarza(Widok widok, Pacjenci pacjenci, Terminarz terminarz)
{
	Wizyta*  wizyta;
	wizyta = terminarz.znajdzWizyte(widok.pobierzPesel(), widok.pobierzInt("Podaj date RRRRMMDD: "), widok.pobierzInt("Podaj godzine GGMM: "));
	wizyta->wynik = widok.pobierzString("Rozpoznanie i opis wizyty, zalecenia: ");
	system("PAUSE");
	return;
}

