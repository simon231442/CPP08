#pragma once

# include <vector>
# include <exception>
# include <iterator>

class Span {
	private :
		unsigned int		sizeMax_;
		std::vector<int>	numbers_;
	public :
		Span();
		Span(unsigned int sizeMax);
		Span(Span const & src);
		~Span();

		Span&				operator=(Span const & rhs);

		void				addNumber(int const & number);
		template <typename InputIt>
		void				addNumbers(InputIt first, InputIt last);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		class alreadyFullException : public std::exception {
			public :
				virtual const char* what() const throw();
				};

		class notEnoughNumbersException : public std::exception {
			public :
				virtual const char*	what() const throw();
				};
		};

template <typename InputIt>
void	Span::addNumbers(InputIt first, InputIt last)
{
	unsigned int	count = std::distance(first, last);

	if (this->numbers_.size() + count > this->sizeMax_)
		throw alreadyFullException();
	this->numbers_.insert(this->numbers_.end(), first, last);
}
