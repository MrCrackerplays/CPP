#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


	int	Account::_nbAccounts;
	int	Account::_totalAmount;
	int	Account::_totalNbDeposits;
	int	Account::_totalNbWithdrawals;

	/** private **/
	void	Account::_displayTimestamp( void ){
		// std::cout << "[19920104_091532] ";
		time_t now = time(0);
		tm *ltm = localtime(&now);
		std::cout << "[" << ltm->tm_year + 1900 << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1 << std::setw(2) << ltm->tm_mday << "_" << std::setw(2) << ltm->tm_hour << std::setw(2) << ltm->tm_min << std::setw(2) << ltm->tm_sec << "] ";
	}

	/** public **/
	void	Account::makeDeposit( int deposit ){
		this->_amount += deposit;
		_totalAmount += deposit;
		this->_nbDeposits++;
		_totalNbDeposits++;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits  << std::endl;
	}
	bool	Account::makeWithdrawal( int withdrawal ){
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
		if (withdrawal > this->_amount)
		{
			std::cout << "refused" << std::endl;
			return (false);
		}
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals  << std::endl;
		return (true);
	}
	int		Account::checkAmount( void ) const {
		return (this->_amount);
	}
	void	Account::displayStatus( void ) const {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	}

	/* constructor & destructor */
	Account::Account( int initial_deposit ){
		this->_amount = initial_deposit;
		this->_totalAmount += initial_deposit;
		this->_accountIndex = _nbAccounts;
		_nbAccounts++;
		this->_nbDeposits = 0;
		this->_nbWithdrawals = 0;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex <<";amount:" << this->_amount << ";created" << std::endl;
	}
	Account::~Account( void ){
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex <<";amount:" << this->_amount << ";closed" << std::endl;
	}

	/* static */
	int	Account::getNbAccounts( void ){
		return (_nbAccounts);
	}
	int	Account::getTotalAmount( void ){
		return (_totalAmount);
	}
	int	Account::getNbDeposits( void ){
		return (_totalNbDeposits);
	}
	int	Account::getNbWithdrawals( void ){
		return (_totalNbWithdrawals);
	}
	void	Account::displayAccountsInfos( void ){
		_displayTimestamp();
		std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	}
