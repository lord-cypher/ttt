#include <stdio.h>

#define HEIGHT 3
#define WIDTH  3

#define SIZE   9

//also make tests for your program
//leaderboard etc.
// git etc.

void boardInit(char **boardp) {
	for (int i = 1; i < SIZE + 1; i++) {
			(boardp[i]) = 'i';
	}
}


void printBoard(char **boardp) {

	// Top Line
	/*
	for (int i = 0; i < WIDTH; i++) {
		printf(" _");
	}
	printf("\n");



	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("|%c", board[i][j]);
		}
		printf("|\n");

		// middle dividers, and bottom line

		for (int i = 0; i < WIDTH; i++) {
			printf(" -");
		}
		printf("\n");
	}
	*/


	for (int i = 1; i < SIZE + 1; i++) {
			printf("%d", (*boardp[i]));
			if (i % 3 == 0) {
				printf("\n");
			}
	}





}



void changeTurn(char turnCharacter) {
	if (turnCharacter == 'O') {
		turnCharacter = 'X';
		return;
	}

	turnCharacter = 'O';
	return;
}

void input() {

	/*
	int a;
	int b;

	scanf('%d' '%d', &a, &b);


	if (a < 0 || b < 0 || a > 3 || b > 3) {
		printf("The coordinates you have selected are out of bounds");
	}

	*/


	//The other amazing idea i had the last time i made ttt, was to have an input system
	//mimic the numpad.

	// bounds checking

	printf("Please select the square where you'd like to place your piece.\n");

	int a = 0;

	scanf("%d", &a);

	printf("You have selected %d\n", a);

	if (a < 0 || a > 9) {
		printf("The coordinates you have selected are out of bounds.\n");
	}





}

void isGameOver(){
	/*
	if () {

	}
	*/
}

int main() {

	char board[SIZE];

	char **boardp = &board;

	int turnNumber = 0;
	char turnCharacter = 'O';


	// Setup

	boardInit(boardp);
	printBoard(boardp);



	// Game Loop
	
	while (1) {
		input();
		changeTurn(turnCharacter);

		if (turnNumber > 5) {
			isGameOver();
		}

		if (turnNumber == 9) {
			printf("The Game has ended in a Draw\n");
		}
		
	}
	





}



/* Lessons learned

there are multiple ways to define the board, which can cause issues/optimisations


if we made everything global, life would be easier














*/