#include "Span.hpp"
#include <iostream>
#include <array>
#include <list>

int main(void) {
	{
		std::cout << "===[20 random numbers]===" << std::endl;
		std::srand(std::time(NULL));
		Span	rnum(20);
		for (int i = 0; i < 20; i++)
		{
			int val = std::rand();
			rnum.addNumber(val);
		}
		std::cout << "rnum shortest span:" << rnum.shortestSpan() << " rnum longest span:" << rnum.longestSpan() << std::endl;
	}

	{
		std::cout << "===[subject example]===" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "===[range of iterators]===" << std::endl;
		std::list<int> ilist;
		for (int i = 0; i < 20; i++)
			ilist.push_back(i * 2 + 1);

		std::array<int, 20> iarray = {1};
		for (int i = 0; i < 20; i++)
			iarray[i] = i * 3 - 1;

		Span spanlist(20);
		Span spanarray(20);
		spanlist.rangeIter<std::list<int> >(ilist.begin(), ilist.end());
		spanarray.rangeIter<std::array<int, 20> >(iarray.begin(), iarray.end());

		std::cout << "list shortest span:" << spanlist.shortestSpan() << " list longest span:" << spanlist.longestSpan() << std::endl;
		std::cout << "array shortest span:" << spanarray.shortestSpan() << " array longest span:" << spanarray.longestSpan() << std::endl;
	}

	{
		std::cout << "===[exceptions]===" << std::endl;
		Span spanner(0);
		try {
			spanner.addNumber(1);
			std::cout << "added beyond size" << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			spanner.shortestSpan();
			std::cout << "span where there is none" << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			spanner.longestSpan();
			std::cout << "span where there is none" << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		
		spanner = Span(1);
		spanner.addNumber(1);

		try {
			spanner.shortestSpan();
			std::cout << "span where there is one" << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			spanner.longestSpan();
			std::cout << "span where there is one" << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "===[very big]===" << std::endl;
		Span spanner(10000001);
		spanner.addNumber(200000000);
		for (int i = 0; i < 10000000; i++)
			spanner.addNumber(i % 3);
		std::cout << "shortest span:" << spanner.shortestSpan() << " longest span:" << spanner.longestSpan() << std::endl;
	}
	// system("leaks span");
}
