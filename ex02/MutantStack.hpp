#pragma once

# include <stack>

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
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>&			MutantStack<T>::operator=(MutantStack const & rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return this->c.end();
}


