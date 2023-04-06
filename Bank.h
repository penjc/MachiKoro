#pragma once
#include <string>

using namespace std;

class Bank{
public:
	Bank();
	void deposit(int val);
	int withdraw(int val);
	int get_coins();
private:
	int coins;
};