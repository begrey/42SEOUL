#include "Account.hpp"
#include <iostream>
#include <string>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{  
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
    //[19920104_091532] index:0;amount:42;created
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits  = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts++;
    this->_totalAmount += this->_amount;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
    << ";created" <<std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
    << ";closed" <<std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t curTime = time(NULL);
    struct tm *t = localtime(&curTime);
    std::cout << "[" << t->tm_year + 1900 << t->tm_mon << t->tm_mday << "_"
    << t->tm_hour << t->tm_min << t->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
}
void	Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
    << ";deposits:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}
bool	Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    //현재 금액보다 출금 금액이 더 많으면 refused
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
    << ";withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
    << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    return true;
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
}
int		Account::checkAmount(void) const
{
    return _amount;
// p_amount:1521;withdrawal:657;amount:864;
// 이전 p_amount 를 기준으로 예금 출금값을 합산하여 다시 amout 반환인듯
}
void	Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
}