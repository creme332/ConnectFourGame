#pragma once
#include <iostream>
using namespace std;

class Game {
private:
    char board [6][7];
    int totalmoves; //number of rounds played so far. If totalmoves = 42, board is full => DRAW
    int nextfree[7];//If nextfree[0] = 2,  coordinates of the next free slot in this column is(2,0)
    const char R = 'R';
    const char Y = 'Y';
    const char null = '.';
    char turn; //whose turn is it?
    string ColorCharacter(char a); //color character a 

public:
    Game();
    void InitialiseTerminal();
    void SwapTurns();
    void UpdateTerminal();

};
