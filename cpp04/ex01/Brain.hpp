#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
protected:
	std::string ideas[100];
public:
	/* Canonical */
	Brain(void);
	Brain(Brain const & src);
	~Brain(void);
	Brain &	operator=(Brain const & rhs);

	/* Specific */
	std::string	getIdea(int i) const;
	void		setIdea(int i, std::string idea);
};

#endif
