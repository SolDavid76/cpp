
#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

int lvl_to_int(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (4);
}

void Harl::complain(std::string level)
{
	void (Harl::*functptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::confusion};
	(this->*functptr[lvl_to_int(level)])();
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
	this->info();
}

void Harl::info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	this->warning();
}

void Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	this->error();
}

void Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::confusion(void)
{
	std::cout << "[CONFUSED]: I don't know what to complain about" << std::endl;
}
