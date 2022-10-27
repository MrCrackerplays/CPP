#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::cout << "===[mutantstack]===" << std::endl;
		MutantStack<int> mstack;
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
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << "===[list]===" << std::endl;
		std::list<int> checklist;
		checklist.push_back(5);
		checklist.push_back(17);
		std::cout << checklist.back() << std::endl;
		checklist.pop_back();
		std::cout << checklist.size() << std::endl;
		checklist.push_back(3);
		checklist.push_back(5);
		checklist.push_back(737);
		checklist.push_back(0);
		std::list<int>::iterator lit = checklist.begin();
		std::list<int>::iterator lite = checklist.end();
		++lit;
		--lit;
		while (lit != lite) {
			std::cout << *lit << std::endl;
			++lit;
		}
	}

	{
		std::cout << "===[vector]===" << std::endl;
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(17);
		std::cout << vec.back() << std::endl;
		vec.pop_back();
		std::cout << vec.size() << std::endl;
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(737);
		vec.push_back(0);
		std::vector<int>::iterator lit = vec.begin();
		std::vector<int>::iterator lite = vec.end();
		++lit;
		--lit;
		while (lit != lite) {
			std::cout << *lit << std::endl;
			++lit;
		}
	}
}