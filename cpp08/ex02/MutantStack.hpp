#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack(void) : std::stack<T>() {};
	MutantStack(MutantStack const & copy) : std::stack<T>(copy) {};

	~MutantStack(void) {};

	MutantStack &	operator=(MutantStack const & rhs) {
		std::stack<T>::operator=(rhs);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin(void) {
		return (this->c.begin());
	}
	iterator	end(void) {
		return (this->c.end());
	}
};

#endif
