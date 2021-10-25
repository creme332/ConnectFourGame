
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string board[6][7]; //6 rows 7 columns
int nextfree[7];//If nextfree[5] = 2, 5th column has next free slot at row 2
int totalmoves; //If totalmoves = 42, board is full - DRAW

void initialise() {
	totalmoves = 0;
	//initialise board
	for (int row = 0;row < 6;row++) {
		for (int col = 0;col < 7;col++) {
			board[row][col] = ".";
		}
	}
	//initialise nextfree to 5
	for (int i = 0;i < 7;i++) {
		nextfree[i] = 5;
	}
}
string hcheck() {
	int red, yellow; //counts for red, yellow
	//start checking from bottom

	for (int row = 5;row > -1;row--) {
		red = 0;
		yellow = 0;
		for (int col = 6;col > -1;col--) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
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

		}
	}
	return "no";
}
string vcheck() {
	int red, yellow; //counts for red, yellow
	//start checking from bottom
	for (int col = 0;col < 7;col++) {
		red = 0;
		yellow = 0;
		for (int row = 5;row > -1;row--) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
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


		}
	}
	return "no";
}
string d1check() { //check along diagonal with negative slope
	int red, yellow; //counts for red, yellow
	int col;

	//startrow = start row for diagonal
	for (int startrow = 2;startrow > -1;startrow--) {
		red = 0;
		yellow = 0;
		col = 0;
		for (int row = startrow;row < 6;row++) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
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
			col++;
		}
	}

	int row;
	for (int startcol = 1;startcol < 4;startcol++) {
		red = 0;
		yellow = 0;
		row = 0;
		for (int col = startcol;col < 7;col++) {
			if (board[row][col] == ".") {
				red = 0;
				yellow = 0;
			}
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
			row--;
		}
	}

	return "no";
}

void output() {
	cout << endl;
	for (int row = 0;row < 6;row++) {
		for (int col = 0;col < 7;col++) {
			cout << board[row][col] << "   ";
		}
		cout << endl;
		cout << endl;
	}
	cout << endl;

}

int main() {
	bool turn=0; //turn 0 for red and turn 1 for yellow
	int colnum;
	string winner="";
	initialise();
	bool validinput;
	
	while (winner != "Red" && winner != "Yellow" && totalmoves <42) {
		validinput = 0;
		while (validinput == 0) {
			if (turn == 0) {cout << "Red, enter column number (0-6) :" << endl;}
			else {cout << "Yellow, enter column (0-6) :" << endl;}
			cin >> colnum;

			if (nextfree[colnum] >= 0) { //if colnum is valid
				validinput = 1;
				if (turn == 0) { board[nextfree[colnum]][colnum] = "R"; }
				else { board[nextfree[colnum]][colnum] = "Y"; }
				totalmoves++;
				nextfree[colnum]--;
				output();
				turn = !turn;

				if (hcheck() == "R" || vcheck() == "R" || d1check() == "R" || d2check() == "R") {
					winner = "Red";
				}
				if (hcheck() == "Y" || vcheck() == "Y" || d1check() == "Y" || d2check() == "Y") {
					winner = "Yellow";
				}
			}
		}
	}

	if (winner == "") {cout << "DRAW" << endl;}
	else {cout << winner << " won!" << endl;}



}

