#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		static const int	fractional = 8;
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
};

#endif