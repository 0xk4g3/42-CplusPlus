// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); // Get total number of accounts
	static int	getTotalAmount( void ); // Get total amount across all accounts
	static int	getNbDeposits( void ); // Get total number of deposits 
	static int	getNbWithdrawals( void ); /// Get total number of withdrawals
	static void	displayAccountsInfos( void ); // Display info for all accounts

	Account( int initial_deposit ); // Constructor with initial deposit
	~Account( void ); // Destructor

	void	makeDeposit( int deposit ); // Make a depoisit
	bool	makeWithdrawal( int withdrawal ); // Make a withdrawal
	int		checkAmount( void ) const; // Check current balance
	void	displayStatus( void ) const; // Display account status


private:

	static int	_nbAccounts;  // Total number of the accounts
	static int	_totalAmount; // Total amount across all accounts 
	static int	_totalNbDeposits; // Total number of deposits made
	static int	_totalNbWithdrawals; // Total number of withdrawals made

	static void	_displayTimestamp( void ); // Display current timestamp

	int				_accountIndex; // unique index for each  account
	int				_amount; // Current balance of this account
	int				_nbDeposits; // Number of deposits  for this account
	int				_nbWithdrawals; // Number of withdrawals for this account

	Account( void ); // Private default constructor (prevented)

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
