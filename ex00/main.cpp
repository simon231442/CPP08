#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <iomanip>

static void	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

int	main(void)
{
	{
		titlePut("test 1: vector as container, search success")
