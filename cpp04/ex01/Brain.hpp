#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
protected:
	std::string idea[100];
public:
	/* Canonical */
	Brain(void);
	Brain(Brain const & src);
	~Brain(void);
	Brain &	operator=(Brain const & rhs);
};

#endif
