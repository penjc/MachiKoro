#include <iostream>
#include "Jeu.h"

using namespace std;

int main()
{
    while (!Jeu::GetInstance().gameover)
    {
        Jeu::GetInstance().rolldice();
        system("pause");
    }
}

