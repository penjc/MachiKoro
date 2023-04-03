#pragma once
#include <string>

using namespace std;

class Banque{
public:
	Banque();
	void deposit(int val);//赢钱
	int withdraw(int val);//失钱
	int get_coins();
private:
	int coins;
};