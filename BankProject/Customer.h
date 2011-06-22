#include <string>
#include "CustomerException.h"
#include <iostream>

class Customer {
private:
	std::string name;
	unsigned int accountNumber;
			 int accountBalance;
			 int amountWithdraw;

	// DRY in action? Less OO more hacky hacky.
	void promptAgain(std::string msg, void (Customer::*setter)(int));

public:
	// customer name
	void setName(std::string);
	std::string getName(void);

	// account number
	void setAccountNumber(unsigned int);
	unsigned int getAccountNumber(void);

	// account balance
	void setAccountBalance(int);
	unsigned int getAccountBalance(void);

	// amount withdraw
	void setAmountWithdraw(int);
	unsigned int getAmountWithdraw(void);
};