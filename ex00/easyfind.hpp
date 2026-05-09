#pragma once

# include <exception>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T & container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Integer not found");
	return it;
}
