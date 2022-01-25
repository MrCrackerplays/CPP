#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	private:
		static const int	fractional_bits = 8;
		int					value;
	public:
		/* Canonical */
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed &	operator=(Fixed const & rhs);

		/* Specific */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed(const int value);
		Fixed(const float value);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f1);

#endif