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

    Game(){
        totalmoves = 0;
	    for (int row = 0;row < 6;row++) {
		    for (int col = 0;col < 7;col++) {board[row][col] = null;}
	    }
	    for (int i = 0;i < 7;i++) {nextfree[i] = 5;}
    }
    string color(string a){ //color character a 
	if(a=="Y")return "\x1B[33mY\033[0m"; //yellow color
	if(a=="R")return "\x1B[31mR\033[0m"; //red
	return "\x1B[92m"+a+"\033[0m"; //cyan
}
void output() {

}

    public:
    void OutputBoard(){

    }

};
