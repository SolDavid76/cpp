
#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl bob;

	if (ac == 2)
		bob.complain(av[1]);
	else
		std::cout << "Wrong number of args" << std::endl;
}