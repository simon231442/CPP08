#pragma once

# include <vector>
# include <exception>

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
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		class alreadyFullException : public std::exception {
			public :
				virtual const char* what() const throw()
				{
					return "vector is already full";
				}
				};
		class notEnoughNumbersException : public std::exception {
			public :
				virtual const char*	what() const throw();
				{
					return "there isn't enough numbers";
				}
				};
		};
