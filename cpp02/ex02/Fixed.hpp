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

		bool operator>(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);
		bool operator==(Fixed const & rhs);
		bool operator!=(Fixed const & rhs);
		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);
		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed & min(Fixed & l, Fixed & r);
		static const Fixed & min(Fixed const & l, Fixed const & r);
		static Fixed & max(Fixed & l, Fixed & r);
		static const Fixed & max(Fixed const & l, Fixed const & r);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f1);

#endif