#include <iostream>
#include <string>

using namespace std;

void draw_board(char[]); // print board at start of game, after each turn

int check_board(char[], unsigned int); // return 0 = no winner yet, return 1 = player 1 win, return 2 = player 2 win, return 3 = tie


int main() {

	unsigned int turn = 0;
	char entry[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

	// print rules
	// print board
	draw_board(entry);
	
	// while game is not over
		// alternate turns between player 1 and 2
		// test if winner / tie / game continues
		// increment turn

	// print winner / tie


  return 0;
}

void draw_board(char arr[]) {

	// printf("FIX ME -- void draw_board()\n\n");

	for (unsigned int i = 0; i < 11; ++i) {
		if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10) {
			printf("        |         |       \n");
		}
		else if (i == 1 || i == 5 || i == 9) {
			printf("    %c   |    %c    |    %c   \n", arr[i / 3], arr[i / 3 + 1], arr[i / 3 + 2]);
		}
		else { // i == 3 || i == 7
			printf("-------   -------   -------\n");
		}
	}
}

int check_board(char arr[], unsigned int turnNum) { 

	printf("FIX ME -- int check_board()");
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

	if (turnNum == 8) {
		return 3;
	}

	return 0;
}