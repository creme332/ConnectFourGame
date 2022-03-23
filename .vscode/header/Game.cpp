#include "Game.h"

Game :: Game (){
    totalmoves = 0;
	for (int row = 0;row < 6;row++) {
	    for (int col = 0;col < 7;col++) {board[row][col] = null;}
	}
	for (int i = 0;i < 7;i++) {nextfree[i] = 5;}
}

string Game:: ColorCharacter(char a){ 
    string s="";s+=a;
	if(a=='Y')return "\x1B[33mY\033[0m"; //yellow color
	if(a=='R')return "\x1B[31mR\033[0m"; //red
	return "\x1B[92m"+s+"\033[0m"; //cyan
}

void Game:: InitialiseTerminal(){
	for (int row = 0;row < 6;row++) {
	    for (int col = 0;col < 7;col++) {
            cout<<board[row][col]<<" ";
        }
        cout<<"\n";
	}
}

void  Game :: SwapTurns(){
	if(turn==R)turn = Y;
	if(turn==Y)turn = R;
}