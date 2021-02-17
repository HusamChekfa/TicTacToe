#include <iostream>
#include <string>

using namespace std;

void draw_board(char[]); // print board at start of game, after each turn

int choose_winner(); // return 0 = no winner yet, return 1 = player 1 win, return 2 = player 2 win, return 3 = tie


int main() {

	char entry[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

	// print rules
	// print board
	draw_board(entry);
	
	// while game is not over
		// alternate turns between player 1 and 2
		// test if winner / tie / game continues

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
			printf("_______   _______   _______\n");
		}
	}
}

int choose_winner() {

	printf("FIX ME -- int choose_winner()");

	return 0;
}