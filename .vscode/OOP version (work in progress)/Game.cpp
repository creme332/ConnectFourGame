#include "Game.h"

Game :: Game (){
    totalmoves = 0;
	for (int row = 0;row < 6;row++) {
	    for (int col = 0;col < 7;col++) {board[row][col] = null;}
	}
	for (int i = 0;i < 7;i++) {nextfree[i] = 5;}
}

std::string Game:: ColorCharacter(char a){ 
    std::string s="";s+=a;
	if(a=='Y')return "\x1B[33mY\033[0m"; //yellow color
	if(a=='R')return "\x1B[31mR\033[0m"; //red
	return "\x1B[92m"+s+"\033[0m"; //cyan
}

void Game:: InitialiseTerminal(){
	for (int row = 0;row < rowsize;row++) {
	    for (int col = 0;col < columnsize;col++) {
           std:: cout<<board[row][col]<<" ";
        }
        std::cout<<"\n";
	}
}

void  Game :: SwapTurns(){
	RedsTurn=!RedsTurn;
}

char Game:: Winner(int i, int j, char player){

	//check along horizontal line passing through (i,j)
	int count=0; 
	//start checking from bottom row
	for (int col = 0;col<columnsize;col++) {
		if (board[i][col] == player) {
			count++;
			if (count == 4) {return player;}
		}else{
			count=0;
		}
	}

	//check along vertical line passing through (i,j)
	count=0;
	for (int row = 0;row<rowsize;row++) {
		if (board[row][j] == player) {
			count++;
			if (count == 4) {return player;}
		}else{
			count=0;
		}
	}
	//check along positive diagonal passing through (i,j)

	//check along negative diagonal passing through (i,j)
}