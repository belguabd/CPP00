#include "Account.hpp"
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos(void)
{
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(NULL);
    char buff[70];
    struct tm timeInfo;

    timeInfo = *localtime(&now);
    strftime(buff, sizeof(timeInfo), "%Y%m%d%H%M%S", &timeInfo);
    std::cout << "[" << buff << "]";
}
int Account::getNbAccounts()
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::makeDeposit(int deposit)
{

    //[19920104_091532] index:0;p_amount:24;deposit:5;amount:47;nb_deposits:1
    if (deposit > 0)
    {
        _nbDeposits++;
        _totalNbDeposits++;
        _totalAmount += deposit;
        int tmp = _amount;
        _amount += deposit;

        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";"
                  << "p_amount:" << tmp << ";"
                  << "deposit:" << deposit << ";"
                  << "amount:" << _amount << ";"
                  << "nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    int tmp = _amount;
    if (withdrawal > 0 && withdrawal <= _amount)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << " index:" << _accountIndex << ";"
                  << "p_amount:" << tmp << ";"
                  << "withdrawal:" << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << " index:" << _accountIndex << ";"
                  << "p_amount:" << tmp << ";"
                  << "withdrawal:" << "refused" << std::endl;
    }
    return (false);
}

int Account::checkAmount(void) const
{
    // index:0;amount:47;deposits:1;withdrawals:0
    //    [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;

    return _amount;
}

void Account::displayStatus(void) const
{
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}
Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex<< ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}
