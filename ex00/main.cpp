#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <iterator>

static void	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

int	main(void)
{
	int	arr[] = {42, 64, 66, 92, 30, 23};

	titlePut("vector generating");
	std::copy(arr, arr + sizeof(arr) / sizeof(int), std::ostream_iterator<int>(std::cout, " "));
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::cout << std::endl;

	titlePut("test 1: vec as container, search success");
	int i = 42;
	try
	{
		easyfind(vec, i);
		std::cout << i << ", integer found" << std::endl; 
	}
	catch (std::exception & e)
	{
		std::cout << i << ", " << e.what() << std::endl;
	}

	titlePut("test 2: vec as container, search faillure");
	i = 2;
	try
	{
		easyfind(vec, i);
		std::cout << i << ", integer found" << std::endl; 
	}
	catch (std::exception & e)
	{
		std::cout << i << ", " << e.what() << std::endl;
	}

	titlePut("test 3: list as container, search success");
	std::list<int> list(vec.begin(), vec.end());
	i = 30;
	try
	{
		easyfind(list, i);
		std::cout << i << ", integer found" << std::endl; 
	}
	catch (std::exception & e)
	{
		std::cout << i << ", " << e.what() << std::endl;
	}

	return 0;
}
