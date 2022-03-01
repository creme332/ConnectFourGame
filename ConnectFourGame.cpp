
#include <iostream>
#include <string>
#include <stdlib.h> //used to clear terminal screen each round


using namespace std;
const string null = "."; const string R = "R"; const string Y = "Y";


string board[6][7]; //6 rows 7 columns
int totalmoves; //number of rounds played so far. If totalmoves = 42, board is full => DRAW
int nextfree[7];//If nextfree[0] = 2,  coordinates of the next free slot in this column is(2,0)
//  c0  c1  c2  c3  c4  c5  c6
//r0 .  .   .   .   .   .   .
//r1 .  .   .   .   .   .   .
//r2 .  .   .   .   .   .   .
//r3 Y  .   .   .   .   .   .
//r4 R  .   .   .   .   .   .
//r5 R  .   .   .   .   .   .
// for this game configuration, nextfree[0]=2 and nextfree[1-6] = 5


void initialise() { 	//initialise board
	totalmoves = 0;
	for (int row = 0;row < 6;row++) {
		for (int col = 0;col < 7;col++) {board[row][col] = null;}
	}
	//initialise nextfree to 5
	for (int i = 0;i < 7;i++) {nextfree[i] = 5;}
}
string hcheck() {//returns player, if any, who has 4 consecutive tokens horizontally
	int red, yellow; //counts for red, yellow
	//start checking from bottom row
	for (int row = 5;row > -1;row--) {
		red = 0; yellow = 0;
		for (int col = 6;col > -1;col--) {
			if (board[row][col] == ".") {red = 0; yellow = 0;}
			else {
				if (board[row][col] == "R") {
					red++; yellow = 0; //streak of yellow ends 
					if (red == 4) {return "R";}
				}
				else {
					if (board[row][col] == "Y") {
						yellow++; red = 0; //streak of red ends 
						if (yellow == 4) {return "Y";}
					}
				}
			}

		}
	}
	return "no";
}
string vcheck() {//returns player, if any, who has 4 consecutive tokens vertically
	int red, yellow; //counts for red, yellow

	for (int col = 0;col < 7;col++) {
		red = 0; yellow = 0;
		for (int row = 5;row > -1;row--) {
			if (board[row][col] == ".") {red = 0; yellow = 0;}
			else {
				if (board[row][col] == "R") {
					red++; yellow = 0; //streak of yellow ends 
					if (red == 4) {return "R";}
				}
				else {
					if (board[row][col] == "Y") {
						yellow++; red = 0; //streak of red ends 
						if (yellow == 4) {return "Y";}
					}
				}
			}
		}
	}
	return "no";
}
string d1check() { //check along diagonal with negative slope
	int red, yellow; //counts for red, yellow
	int col;

	//startrow = start row for diagonal
	for (int startrow = 2;startrow > -1;startrow--) {
		red = 0; yellow = 0; col = 0;
		for (int row = startrow;row < 6;row++) {
			if (board[row][col] == ".") {red = 0; yellow = 0;}
			else {
				if (board[row][col] == "R") {
					red++; yellow = 0; //streak of yellow ends 
					if (red == 4) {return "R";}
				}
				else {
					if (board[row][col] == "Y") {
						yellow++; red = 0; //streak of red ends 
						if (yellow == 4) {return "Y";}
					}
				}
			}
			col++;
		}
	}

	int row;
	for (int startcol = 1;startcol < 4;startcol++) {
		red = 0; yellow = 0; row = 0;
		for (int col = startcol;col < 7;col++) {
			if (board[row][col] == ".") {red = 0; yellow = 0;}
			else {
				if (board[row][col] == "R") {
					red++;
					yellow = 0; //streak of yellow ends 
					if (red == 4) {
						return "R";
					}
				}
				else {
					if (board[row][col] == "Y") {
						red = 0; //streak of red ends 
						yellow++;
						if (yellow == 4) {
							return "Y";
						}
					}
				}
			}
			row++;
		}
	}
	return "no";
}
string d2check() { //check along diagonal with positive slope
	int red, yellow; //counts for red, yellow
	int col;
	//startrow = start row for diagonal
	for (int startrow = 3;startrow < 6;startrow++) {
		red = 0;
		yellow = 0;
		col = 0;
		for (int row = startrow;row > -1;row--) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
			else {
				if (board[row][col] == "R") {
					red++;
					yellow = 0; //streak of yellow ends 
					if (red == 4) {return "R";}
				}
				else {
					if (board[row][col] == "Y") {
						red = 0; //streak of red ends 
						yellow++;
						if (yellow == 4) {return "Y";}
					}
				}
			}

			col++;
		}
	}

	int row;
	for (int startcol = 1;startcol < 4;startcol++) {
		red = 0;
		yellow = 0;
		row = 5;
		for (int col = startcol;col < 7;col++) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
			else {
				if (board[row][col] == "R") {
					red++;
					yellow = 0; //streak of yellow ends 
					if (red == 4) {return "R";}
				}
				else {
					if (board[row][col] == "Y") {
						red = 0; //streak of red ends 
						yellow++;
						if (yellow == 4) {return "Y";}
					}
				}
			}
			row--;
		}
	}

	return "no";
}

string color(string a){ //color character a 
	if(a=="Y")return "\x1B[33mY\033[0m"; //yellow color
	if(a=="R")return "\x1B[31mR\033[0m"; //red
	return "\x1B[92m"+a+"\033[0m"; //cyan
}
void output() {
	system("CLS"); //clear previous board from terminal
	string line = "|---|---|---|---|---|---|---|"; //horizontal line
	cout << color(line)<<"\n";
	for (int row = 0;row < 6;row++) {
		for (int col = 0;col < 7;col++) {
			if(col==0){cout << color("| ")<< color(board[row][col]) << color(" |");}
			else{cout <<" "<< color(board[row][col]) << color(" |");}
		}
	cout <<"\n" <<color(line)<<"\n";
	}
}

string GameState(){
	if (hcheck() == R || vcheck() == R || d1check() == R || d2check() == R) {
		return R;
	}
	if (hcheck() == Y || vcheck() == Y || d1check() == Y || d2check() == Y) {
		return Y;
	}
	return "no winner yet";
}
int minimax(int depth, bool maximizingplayer,int alpha, int beta) {
    string result = GameState();
    //if game over
    if (result == "R")return 100; //AI is maximising player
    if (result == "Y")return -100;
    if (totalmoves == 42)return 0;

    int MaxEval = -1000; //max score for maximising player
    int MinEval = 1000; //min score for minimising player

        for (int j = 0;j < 7;j++) {
            if (board[nextfree[j]][j] == null) {
                board[nextfree[j]][j] = maximizingplayer ? R : Y;
				nextfree[j] --;
				totalmoves ++;
                if (maximizingplayer) {
                    MaxEval = max(MaxEval, minimax(depth + 1, 0, alpha, beta) - depth);
                    alpha = max(alpha, MaxEval);
                }
                else {
                    MinEval = min(MinEval, minimax(depth + 1, 1, alpha, beta) + depth);
                    beta = min(beta, MinEval);
                }
                board[nextfree[j]][j] = null;
				nextfree[j] ++;
				totalmoves --;
                if (beta <= alpha)break;
            }
        }
    return maximizingplayer == 1 ? MaxEval : MinEval;
}

void AImove() { 
    int p = -1; //best move is to play at column p
    int MaxEval = INT_MIN;
    for (int j = 0;j < 7;j++) {
        if (nextfree[j]>=0) {//possible play
			board[nextfree[j]][j] = R;
			nextfree[j] --;
			totalmoves ++;
        	int eval = minimax(0, 0, -9999, 9999); //must start at depth 0
        	if (eval > MaxEval) {//new best move discovered
        		p = j;
            	MaxEval = eval;
        	}
			//reset board to its previous state
			board[nextfree[j]][j] = null;
			nextfree[j] ++;
			totalmoves --;
        }
    }
    
	board[nextfree[p]][p] = R;
	nextfree[p]--;		
	//no need to update totalmoves		

}


int main() {
	bool vsAI = 0;
	bool turn=0; //turn 0 for red and turn 1 for yellow
	int colnum; string winner=""; bool validinput;
	initialise();
    output();

	while (winner != "Red" && winner != "Yellow" && totalmoves < 42) {

		if(vsAI){ //1 player mode
			if(turn==0){//AI's turn - RED
				AImove();
			}else{ //Yellow's turn
				cout << "Yellow : Enter column number (0-6) :" << endl;
				cin >> colnum;
				while(colnum < 0 || colnum > 6 || nextfree[colnum] < 0){
					cout<<"Enter again.\n";
					cin >> colnum;
				}
				board[nextfree[colnum]][colnum] = "Y";
				nextfree[colnum]--;				
			}
		}
		else{ //2 player mode
			if (turn == 0) {cout << "Red : Enter column number (0-6) :" << endl;}
			else {cout << "Yellow : Enter column number (0-6) :" << endl;}
			cin >> colnum;
			while(colnum < 0 || colnum > 6 || nextfree[colnum] < 0){
				cout<<"Enter again.\n";
				cin >> colnum;
			}
		    board[nextfree[colnum]][colnum] = (turn==0)? "R":"Y";
			nextfree[colnum]--;
		}

		output();
		turn = !turn;
		string state=  GameState();
		if(state==R)winner="Red";
		if(state==Y)winner="Yellow";
		totalmoves++;
	}

	if (winner == "") {cout << "DRAW" << endl;}
	else {cout << winner << " won!" << endl;}
}

