#include "Bank.h"

Bank::Bank()
{
	coins = 3;
}
int Bank::get_coins()
{
	return coins;
}

void Bank::deposit(int val)
{
	coins += val;
}

int Bank::withdraw(int val)
{
	if (val > coins)
	{
	    val=coins;
		coins = 0;
	}
	else {
        coins -= val;
    }
    return val;
}
