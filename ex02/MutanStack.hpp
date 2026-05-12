#pragma once

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();

		MutantStack&		operator=(MutantStack const & rhs);

		typedef typename	std::stack<T>::container_type::iterator iterator;

		iterator			begin(void);
		iterator			end(void);
};

template <typename T>
MutantStack::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack::MutantStack(MutantStack const & src) : stack<T>(src) {}

template <typename T>
MutantStack&			MutantStack::operator=(MutantStack const & rhs);
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
MutantStack::iterator	MutantStack::begin(void)
{
	return (c.begin());
}

template <typename T>
MutantStack::iterator	MutantStack::end(void)
{
	return (c.end());
}


