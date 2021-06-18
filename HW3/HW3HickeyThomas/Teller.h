#pragma once

#include "CustomerArray.h"

using namespace std;

int tellerList[4][2];

void teller(Customer &customer)
{
	if (customer.transType == 'D')
	{
		customer.balance = customer.balance + customer.amount;
		tellerList[customer.teller][0]++;
	}

	else
	{
		customer.balance = customer.balance - customer.amount;
		tellerList[customer.teller][1]++;
	}
}

int tellerTotal(int teller)
{
	int total = tellerList[teller][0] + tellerList[teller][1];
	return total;
}

int tellerD(int teller)
{
	int deposits = tellerList[teller][0];
	return deposits;
}

int tellerW(int teller)
{
	int withdrawals = tellerList[teller][1];
	return withdrawals;
}