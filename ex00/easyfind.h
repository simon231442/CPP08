#pragma once

# include <exception>
# include <algorythm>

class notFoundException : public std::exception {
	public :
		virtual char const*	what() throw()
		{
			return "Integer not found";
		}
	};
	
template <typename T>
typename T::iterator	easyfind(T const & container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == &container.last)
		throw notFountException;
	return it;
}
