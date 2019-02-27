#pragma once
#include "stdafx.h"
#include <iostream>


class Widok {
	char wybor;
public:
	char pobierzInput();
	void ustawInputJako(char input);
	void menuGlowne();
	void widokRejestracja();
	void widokLekarza();

	std::string pobierzPesel();

	int pobierzInt(std::string tekst);

	std::string pobierzString(std::string tekst);

};


