#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <list>
# define DATA_FILE "data.csv"

class BitcoinExchange {
public:
	class Date {
	public:
		int	year;
		int	month;
		int	day;
	public:
		Date(std::string date);
		~Date(void);
		bool operator>(Date const & rhs) const;
		bool operator<(Date const & rhs) const;
		bool operator==(Date const & rhs) const;
		bool operator>=(Date const & rhs) const;
		bool operator<=(Date const & rhs) const;
	private:
		Date(void);
		Date & operator=(Date const & rhs);
	};
protected:
	std::list<std::pair<BitcoinExchange::Date, double> >	_history;
public:
	BitcoinExchange(void);

	~BitcoinExchange(void);

	double	getClosestPrice(BitcoinExchange::Date const & date);

private:
	BitcoinExchange & operator=(BitcoinExchange const & rhs);
	BitcoinExchange(BitcoinExchange const & src);
};

#endif
