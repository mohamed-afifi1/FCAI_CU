#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//File: CS112_A1_T5_20230618.cpp
/* Purpose: This is a two-player mathematical game of strategy. It is played by two 
people with a pile of coins (or other tokens) between them. The players take turns removing 
coins from the pile, always removing a non-zero square number of coins (1, 4, 9, 16, …). 
The player who removes the last coin wins.

 Author: mohamed ayman afifi

 ID: 20230618

 Date: 3/3/2024
*/

bool isdigit(string str)
{
    for (char ch : str)
    {
        if(!(ch>='0' && ch<='9'))
        return false;
    }
    return true;
        


}
int your_turn1()
{
    while (true) 
    {
        string strnum;
        cout << "Player 1 -> Enter a square number to subtract: ";
        cin >> strnum;

        if(!isdigit(strnum))
        {
            cout << "Please enter a valid positive integer." << endl;
        } 
        else 
        {
            int num = stoi(strnum);
            double sqrtResult = sqrt(num);
            if (abs(sqrtResult - round(sqrtResult)) < 1e-9)
            {
                return num;
            } 
            else
            {
                cout << "This is not a perfect square number." << endl;
            }
        }
    }
}

int your_turn2()
{
    while (true) 
    {
        string strnum;
        cout << "Player 2 -> Enter a square number to subtract: ";
        cin >> strnum;

        if (!isdigit(strnum))
        {
            cout << "Please enter a valid positive integer." << endl;
        } 
        else 
        {
            int num = stoi(strnum);
            double sqrtResult = sqrt(num);
            if (abs(sqrtResult - round(sqrtResult)) < 1e-9)
            {
                return num;
            } 
            else
            {
                cout << "This is not a perfect square number." << endl;
            }
        }
    }
}

int getcoins() {
    int num;
    string strnum;
    while (true) {
        cout << "Enter a positive number of coins in the pile: ";
        cin >> strnum;

        if (!isdigit(strnum)) {
            cout << "Please enter a valid positive integer." << endl;
        } else {
            num = stoi(strnum);
            if (num <= 0) {
                cout << "Please enter a positive number." << endl;
            } else {
                break;
            }
        }
    }
    return num;
}

int main()
{
    string again = "yes";

    while (again == "yes") {
        int coins = getcoins();
        cout << "The number of coins in the pile is: " << coins << endl;

        while (true) {
            // Player 1's turn
            int player1 = your_turn1();
            coins -= player1;
            if (coins <= 0) {
                cout << "Player 2 wins!" << endl;
                break;
            }
            cout << "Coins left: " << coins << endl;

            // Player 2's turn
            int player2 = your_turn2();
            coins -= player2;
            if (coins <= 0) {
                cout << "Player 1 wins!" << endl;
                break;
            }
            cout << "Coins left: " << coins << endl;
        }

        cout << "If you want to play again, press 'yes': ";
        cin >> again;
    }

    return 0;
}