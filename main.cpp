#include <iostream>
#include <string>

using namespace std;

void draw_board(const char[]); // print board at start of game, after each turn

int check_board(const char[], const unsigned int); // return 0 = no winner yet, return 1 = player 1 win, return 2 = player 2 win, return 3 = tie


int main() {

	unsigned int turn = 1; // game ends after turn 9
	unsigned int check = 0; // modified by check_board() call
	bool playerTurn = true; // true = player 1 turn; false = player 2 turn
	char choice = ' ';
	char player1 = 'X'; // player1 symbol
	char player2 = 'O'; // player2 symbol
	char entry[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

	// print rules
	// print board
	draw_board(entry);
	
	// can place the while loop in a function - call it in a while loop
	while (check == 0) {
		// ascii for 'A' = 65
		string choosePrint = "";

		choosePrint += "Player ";
		if (playerTurn) { choosePrint += "1 "; }
		else { choosePrint += "2 "; }
		choosePrint += "Choose a letter: ";
		for (unsigned int i = 0; i < 9; ++i) {
			if (entry[i] != player1 && entry[i] != player2) {
				choosePrint += entry[i];
				choosePrint += ' ';
			}
		}
		choosePrint += '\n';

		bool validChoice = false;

		while (!validChoice) {
			printf("%s", choosePrint.c_str());
			choice = ' ';
			cin >> choice;
			if (entry[choice - 65] == choice) { validChoice = true; } // 'A' is 65 in ascii
		}
		
		if (choice >= 65 && choice <= 73) {
			if (playerTurn) {
				entry[choice - 65] = player1;
				playerTurn = !playerTurn;
			}
			else {
				entry[choice - 65] = player2;
				playerTurn = !playerTurn;
			}
		}

		draw_board(entry);
		check = check_board(entry, turn);
		
		++turn;
	}

	if (check == 1) {
		printf("Player 1 wins !\n");
	}
	else if (check == 2) {
		printf("Player 2 wins !\n");
	}
	else if (check == 3) {
		printf("'Tis a tie !\n");
	}

  return 0;
}

void draw_board(const char arr[]) {
	
	for (unsigned int i = 0; i < 11; ++i) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10) {
			printf("        |         |       \n");
		}
		else if (i == 1 || i == 5 || i == 9) {
			printf("    %c   |    %c    |    %c   \n", arr[((i - 1) % 3) * 3], arr[(((i - 1) % 3) * 3) + 1], arr[(((i - 1) % 3) * 3) + 2]);
			// (((i - # spaces showing up the char in the block ) mod or div by # lines in block ) * # of lines in block) + 0 / 1 / 2 ... depending on block and num of blocks in row
		}
		else { // i == 3 || i == 7
			printf("-------   -------   -------\n");
		} 
	}
	printf("\n");
}

int check_board(const char arr[], const unsigned int turnNum) { 

	char player1 = 'X';
	char player2 = 'O';

	// return 0 = no winner yet, return 1 = player 1 win, return 2 = player 2 win, return 3 = tie

	// check rows - row 1 = arr[0, 1, 2] - row 2 = arr[3, 4, 5] - row 3 = arr[6, 7, 8]

	for (unsigned int i = 0; i < 3; ++i) {
		if (arr[3 * i] == arr[3 * i + 1] && arr[3 * i] == arr[3 * i + 2]) {
			if (arr[3 * i] == player1) { return 1; }
			else if (arr[3 * i] == player2) { return 2; }
		}
	}

	// check columns - column 1 = arr[0, 3, 6] - column 2 = arr[1, 4, 7] - column 3 = arr[2, 5, 8]

	for (unsigned int i = 0; i < 3; ++i) {
		if (arr[i] == arr[i + 3] && arr[i] == arr[i + 6]) {
			if (arr[i] == player1) { return 1; }
			else if (arr[i] == player2) { return 2; }
		}
	}

	// check majour diagonals - diagonal 1 = arr[0, 4, 8] - diagonal 2 = arr[2, 4, 6]

	if (arr[0] == arr[4] && arr[4] == arr[8]) { // implies arr[0] == arr[2]
		if (arr[0] == player1) { return 1; }
		else if (arr[0] == player2) { return 2; }
	}
	else if (arr[2] == arr[4] && arr[4] == arr[6]) { // implies arr[0] == arr[2]
		if (arr[2] == player1) { return 1; }
		else if (arr[2] == player2) { return 2; }
	}

	if (turnNum == 9) {
		return 3;
	}

	return 0;
}