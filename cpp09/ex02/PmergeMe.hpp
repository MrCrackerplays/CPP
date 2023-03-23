#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {
protected:
	/*Attributes*/
public:
	PmergeMe(/*Args*/);
	PmergeMe(PmergeMe const & src);

	~PmergeMe(void);

	PmergeMe & operator=(PmergeMe const & rhs);
};
#endif
