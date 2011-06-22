#include "stdafx.h"

void Customer::setAccountNumber(unsigned int _number) {
	accountNumber = _number;
}

unsigned int Customer::getAccountNumber(void) {
	return accountNumber;
}

void Customer::setName(std::string _name) {
	name = _name;
}

std::string Customer::getName(void) {
	return name;
}

/*
 * The two juicy functions below could be broken down further in similar
 * fashion to what I did with promptAgain (hey, I wanted to learn something from this)
 */

void Customer::setAccountBalance(int _amount) {
	try {
		if (_amount < 0) {
			throw _amount;
		}

		else {
			accountBalance = _amount;
		}
	}

	catch (int) {
		promptAgain(
			"The amount you entered was a negative number",
			&Customer::setAccountBalance
		);
	}
}

unsigned int Customer::getAccountBalance(void) {
	return accountBalance;
}

void Customer::setAmountWithdraw(int _amount) {
	try {
		if (_amount > accountBalance) {
			throw _amount;
		}

		else {
			amountWithdraw = _amount;
		}
	}

	catch (int) {
		promptAgain(
			"You have insufficient funds in your account",
			&Customer::setAmountWithdraw
		);
	}
}

unsigned int Customer::getAmountWithdraw(void) {
	return amountWithdraw;
}

void Customer::promptAgain(std::string msg, void (Customer::*setter)(int)) {
	std::cout << msg << ". Please try again: ";
	unsigned int amount; 
	std::cin >> amount;
	(this->*setter)(amount);
}