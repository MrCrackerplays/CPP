#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
protected:
	int	*_span;
	unsigned int _max_size;
	unsigned int _current_size;
public:
	Span(unsigned int n);
	Span(Span const & copy);

	~Span(void);

	Span &	operator=(Span const & rhs);

	void			addNumber(int number);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	template<class T> void	rangeIter(typename T::iterator begin, typename T::iterator end) {
		while (begin != end) {
			addNumber(*begin);
			begin++;
		}
	}
private:
	Span(void);
};

#endif
