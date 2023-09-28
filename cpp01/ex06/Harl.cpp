
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
	return (-1);
}

void Harl::complain(std::string level)
{
	switch (lvl_to_int(level))
	{
	case (0):
		this->debug();
	case (1):
		this->info();
	case (2):
		this->warning();
	case (3):
		this->error();
		break;
	default:
		this->confusion();
	}
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::confusion(void)
{
	std::cout << "[CONFUSED]: Probably complaining about insignificant problems..." << std::endl;
}
