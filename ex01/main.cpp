#include "Span.hpp"
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

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
		newNumber = std::rand() % 60;
		std::cout << newNumber << " ";
		span.addNumber(newNumber);
	}
	std::cout << std::endl;
	titlePut("test 1: get the shortest span (success)");
	std::cout << span.shortestSpan() << std::endl;

	titlePut("test 2: get the longest span (success)");
	std::cout << span.longestSpan() << std::endl;

	titlePut("test 3: longest span (failure)");
	Span	onlyOneNumber(1);
	onlyOneNumber.addNumber(42);
	try
	{
		onlyOneNumber.longestSpan();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	titlePut("test 4: addNumber(failure)");
	try
	{
		onlyOneNumber.addNumber(66);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	titlePut("test 5: addNumbers with list which contain 10 000 int (success)");
	std::list<int>	bigList;
	for (int i = 0; i < 10000; i++)
		bigList.push_back(std::rand() % 100);

	Span			bigSpan(10000);
	bigSpan.addNumbers(bigList.begin(),bigList.end());
	std::cout << "shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "longest: " << bigSpan.longestSpan() << std::endl;
	return 0;
}
