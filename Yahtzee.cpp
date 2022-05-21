#include <iostream>
#include <string>
using namespace std;

int rollDice()
{
    int dice1 = rand() % 6 + 1;
    return dice1;
}

int main()
{

    int dice1 = rollDice();
    int dice2 = rollDice();
    int dice3 = rollDice();
    int dice4 = rollDice();
    int dice5 = rollDice();
    int count = 1;
    while (!(dice1 == dice2 && dice2 == dice3))
    {
        // we need to re-roll
        dice1 = rollDice();
        dice2 = rollDice();
        dice3 = rollDice();
        dice4 = rollDice();
        dice5 = rollDice();
        count = count + 1;
    }
    cout << count << endl;
    string names[] = {
        "Yahtzee",
        "Chance",
        "Ones",
        "Twos",
        "Threes",
        "Fours",
        "Fives",
        "Sixes"};
    int leng = 0;
    int ind;
    for (int i = 0; i < (sizeof(names) / sizeof(names[0])); i++)
    {
        if (leng < names[i].length())
        {
            leng = names[i].length();
            ind = i;
        }
    }
    cout << names[ind] << endl;

    return 0;
}