#include "Span.hpp"
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>

static void	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

int	main(void)
{
	titlePut("Span object with random value");
	std::srand(std::time(NULL));
	Span	span(8);
	int		newNumber;

	for (int i = 0; i < 8; i++)
	{
		newNumber = std::rand();
		std::cout << newNumber << " ";
		span.addNumber(newNumber);
	}
	std::cout << std::endl;
	titlePut("test 1: get the shortest span (success)");
	std::cout << span.shortestSpan() << std::endl;

	titlePut("test 2: get the longest span (success)");
	std::cout << span.longestSpan() << std::endl;

	return 0;
}
