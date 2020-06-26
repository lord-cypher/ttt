#include <stdio.h>
#include <ctype.h>

#define HEIGHT 3
#define WIDTH  3

#define SIZE   9

//also make tests for your program
//leaderboard etc.
// git etc.

char board[SIZE] = {'7', '8', '9', '4', '5', '6', '1', '2', '3'};

int turnNumber = 0;
char turnChar = 'O';

int square(int x) {
	switch (x) {
		
		case 1: {
			return 6;
			break;
		}

		case 2: {
			return 7;
			break;
		}

		case 3: {
			return 8;
			break;
		}

		case 4: {
			return 3;
			break;
		}

		case 5: {
			return 4;
			break;
		}

		case 6: {
			return 5;
			break;
		}

		case 7: {
			return 0;
			break;
		}

		case 8: {
			return 1;
			break;
		}

		case 9: {
			return 2;
			break;
		}

	}
}

void printBoard() {

	for (int i = 0; i < SIZE; i++) {
			
			printf("%c", (board[i]));
			if ( (i + 1) % 3 == 0 ) {
				printf("\n");
			}
	}

}

void changeTurn() {
	if (turnChar == 'O') {
		turnChar = 'X';
		return;
	}

	turnChar = 'O';
	return;
}

void input() {

	printf("\nPlease select the square where you'd like to place your piece.\n\n");

	int a = 0;

	scanf("%d", &a);

	printf("\nYou have selected %d\n\n", a);

	if (isdigit(a) == 0) {
		printf("\n You have not provided a numerical value\n\n");
	}

	if (a < 1 || a > 9) {
		printf("\nThe coordinates you have selected are out of bounds.\n\n");
		return;
	}

	a = square(a);

	if ( isdigit(board[a]) == 0 ) {
		printf("\nThe square you have chosen is occupied\n\n");
		return;
	}

	

	board[a] =  turnChar;
	turnNumber++;

	// if the piece isn't '-' dont let the move take place
	changeTurn();

}

void win(char c) {
	printf("%c is the Winner!", c);
}

void isGameOver(){
	
	for (int i = 0; i < 9; i += 3) {
		if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
			win(board[i]);
		}
	}

	for (int i = 0; i < 3; i++) {
		if (board[i] == board[i + 3] && board[i] == board[i + 6]){
			win(board[i]);
		}
	}

	if ( (board[0] == board[4] && board[0] == board[8]) ||
		 (board[6] == board[4] && board[6] == board[3])) 
	{
		win(board[4]);
	}
	
}

int main() {

	printBoard();
	
	while (1) {


		input();
		printBoard();


		if (turnNumber > 5) {
			isGameOver();
		}

		if (turnNumber == 9) {
			printf("The Game has ended in a Draw\n");
			return 0;
		}

	}

}



/* Lessons learned

there are multiple ways to define the board, which can cause issues/optimisations


if we made everything global, life would be easier



Wonder how to print different colours in the terminal



In C probably a good idea to declare all functions at the start, and then implement them. So the compiler doesn't cry.


Why did it take 5 hours to write something as simple as tic tac toe?

more planning required to save time.




1 issue, inputting non digit causes issues






*/