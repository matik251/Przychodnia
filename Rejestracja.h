#pragma once
#include "stdafx.h"
#include "Widok.h"
#include "Listy.h"
#include <Windows.h>


class Obsluga {
public:
	void przychodnia();
};

class RejestracjaObsluga {
public:
	void obslugaRejestracji(Widok widok, Pacjenci pacjenci, Terminarz terminarz);
	void dodajPacjenta(Widok widok, Pacjenci pacjenci);
	void usunPacjenta(Widok widok, Pacjenci pacjenci);
	void umowWizyte(Widok widok, Pacjenci pacjenci, Terminarz terminarz);

};

class LekarzObsluga {
public:
	void obslugaLekarza(Widok widok, Pacjenci pacjenci, Terminarz terminarz);
};