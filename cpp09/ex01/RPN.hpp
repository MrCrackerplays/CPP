#ifndef RPN_HPP
# define RPN_HPP
# include <string>
class RPN {
protected:
	const std::string _string;
public:
	RPN(const std::string string);
	~RPN(void);

	void	solve(void) const;
private:
	RPN(void);
	RPN(RPN const & src);
	RPN & operator=(RPN const & rhs);
};
#endif
