#ifndef DATA_HPP
# define DATA_HPP
class Data {
protected:
	int	_value;
public:
	Data(void);
	Data(Data const & copy);

	~Data(void);

	Data &	operator=(Data const & rhs);

	int		getValue(void) const;
	void	setValue(int value);
};

#endif
