#pragma once
#include <iostream>
#include <vector>

class Game {
private:
    const int rowsize = 6;
    const int columnsize = 7;
    char board [6][7];
    int totalmoves; //number of rounds played so far. If totalmoves = 42, board is full => DRAW
    int nextfree[7];//If nextfree[0] = 2,  coordinates of the next free slot in this column is(2,0)
    const char R = 'R';
    const char Y = 'Y';
    const char null = '.';
    bool RedsTurn; //is it Red's turn to play?
    std::string ColorCharacter(char a); //color character a 

public:
    Game();
    void InitialiseTerminal();
    void SwapTurns();
    void UpdateTerminal();
    char Winner(int i, int j, char player); //did move at (i,j) lead to a win

};
