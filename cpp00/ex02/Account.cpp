

#include "Account.hpp"
#include <iostream>
#include <ctime>






int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;




void Account::_displayTimestamp(void){
     std::cout<< " [19920104_091532]  ";
}


Account::Account(int initial_deposit){
       _accountIndex = _nbAccounts;
       _amount = initial_deposit;
       _nbDeposits = 0;
       _nbWithdrawals =0;
       _totalAmount  += initial_deposit;
       _nbAccounts++;
       _displayTimestamp();
       std::cout << "index:" << _accountIndex << ";";
       std::cout << "amount:" << _amount << ";";
       std::cout << "created" << std::endl;
}

int Account::getNbAccounts(void){
     return _nbAccounts;
}
int Account::getTotalAmount(void){
    return _totalAmount;
}
int Account::getNbDeposits(void){
     return _totalNbDeposits;
}
int  Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
     _displayTimestamp();
     std::cout << "accounts:" << _nbAccounts << ";";
     std::cout << "total:" << _totalAmount << ";";
     std::cout << "deposits:" << _totalNbDeposits << ";";
     std::cout << "withdrawals:" << _totalNbWithdrawals <<std::endl;
}

void Account::makeDeposit(int deposit){
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
     std::cout << "deposit:" << deposit << ";";

     _amount += deposit;
     _totalAmount += deposit;
     _nbDeposits++;
     _totalNbDeposits++;
     std::cout << "amount:" << _amount << ";";     
    std::cout << "nb_deposits:" << _nbDeposits << std::endl; 
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";    
    std::cout << "p_amount:" << _amount << ";";  
      if(_amount >= withdrawal){
           _amount -= withdrawal;
           _totalAmount -= withdrawal;
           _nbWithdrawals++;
         _totalNbWithdrawals++; 
        std::cout << "withdrawal:" <<  withdrawal << ";";
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
      }
      else{
        std::cout << "withdrawal:refused" << std::endl;
        return false;
      }
      return false;

}
int Account::checkAmount(void) const {
    return _amount;
}
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}