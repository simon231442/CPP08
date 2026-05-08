#include "Span.hpp"
#include <algorithm>

Span::Span() : sizeMax_(0) {}

Span::Span(unsigned int sizeMax) : sizeMax_(sizeMax) {
	numbers_.reserve(sizeMax);
}

Span::Span(Span const & src) : sizeMax_(src.sizeMax_), numbers_(src.numbers_) {}

Span::~Span() {}

Span&		Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		sizeMax_ = rhs.sizeMax_;
		numbers_ = rhs.numbers_;
	}
	return *this;
}

void		Span::addNumber(int const & number)
{
	if (this->numbers.size() >= this->sizeMax_)
		throw (alreadyFullException);
	this->numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void)
{
	if (this->numbers_.size() < 2)
		throw (notEnoughNumbersException);
	std::vector<int>	numbersCopy(this->numbers_);
	std::sort(numbersCopy);
	std::vector<int>::iterator	it(numbersCopy.begin());
	int 				spanCurrent;
	int					spanShortest;
	spanShortest = *it; 
	spanShortest = *(++it) - spanShortest;
	while (1)
	{
		SpanCurrent = *it;
		if (++it == numbersCopy.end())
			return spanShortest;
		SpanCurrent = *it - SpanCurrent;
		if (spanCurrent < spanShortest)
			spanShortest = spanCurrent;
	}
}


