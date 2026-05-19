#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <list>

static void	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

int	main(void)
{
	{
		titlePut("test 1: creation mutantstack, modification en testant plusieurs operateur stack et operateur de l'iterateur (main sujet) + verification des propriete inerent del'heritage");
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
	
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack); //permet de verifier que mutantstack est bien fait par eritage de la classe stack
	}

	{
		titlePut("test 2: meme operation que dans le main mais sur un conteneur de type list");
		std::list<int>		lalist;
		lalist.push_back(5);
		lalist.push_back(17);
	
		std::cout << lalist.back() << std::endl;
		lalist.pop_back();
	
		std::cout << lalist.size() << std::endl;
		lalist.push_back(3);
		lalist.push_back(5);
		lalist.push_back(737);
		//[...]
		lalist.push_back(0);
		std::list<int>::iterator it = lalist.begin();
		std::list<int>::iterator ite = lalist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		titlePut("test 3: test de la forme canonique (copie et assignation)");
		
		MutantStack<int> mstack_orig;
		mstack_orig.push(42);
		mstack_orig.push(21);
		mstack_orig.push(84);

		std::cout << std::setw(50) << std::left << "Original stack size:" << mstack_orig.size() << std::endl;

		// Test de construction par copie
		MutantStack<int> mstack_copy(mstack_orig);
		std::cout << std::setw(50) << std::left << "Copy stack size (after copy constructor):" << mstack_copy.size() << std::endl;

		// Test d'assignation
		MutantStack<int> mstack_assign;
		mstack_assign.push(1); // On met un element bidon
		mstack_assign = mstack_orig;
		std::cout << std::setw(50) << std::left << "Assign stack size (after operator=):" << mstack_assign.size() << std::endl;

		// Modification de l'original pour prouver la copie profonde
		mstack_orig.pop();
		mstack_copy.push(1);
		mstack_assign.push(3);
		mstack_assign.push(42);
		std::cout << "\n--- Apres mstack_orig.pop() ---" << std::endl;
		std::cout << std::setw(50) << std::left << "Original stack size:" << mstack_orig.size() << std::endl;
		std::cout << std::setw(50) << std::left << "Copy stack size:" << mstack_copy.size() << std::endl;
		std::cout << std::setw(50) << std::left << "Assign stack size:" << mstack_assign.size() << std::endl;
	}

	return 0;
}
