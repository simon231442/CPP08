#pragma once

# include <exception>
# include <algorithm>

class notFoundException : public std::exception {
	public :
		virtual char const*	what() const throw()
		{
			return "Integer not found";
		}
	};
	
template <typename T>
typename T::iterator	easyfind(T & container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw notFoundException();
	return it;
}
