#include "Banque.h"

Banque::Banque()
{
	coins = 3;
}
int Banque::get_coins()
{
	return coins;
}
//玩家得到金币
void Banque::deposit(int val)
{
	coins += val;
}
//玩家消耗金币
int Banque::withdraw(int val)
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
