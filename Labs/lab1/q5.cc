#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	srand( time( NULL ) );
	int num = rand()%100; // random number from 1 to 100
	printf ("First number: %d\n", num);
	
	int guess = 0;
	bool endgame = 0;
	char buffer_guess[256];
	char buffer_exit[256];
	
	while (guess != num && endgame == 0){
		printf ("Guess a number from 1 to 100.\n");
		fgets (buffer_guess, 256, stdin);
		guess = atoi (buffer_guess);
		if (guess == num){
			printf("Congrats! You guessed correctly.\n");
		} 
		else {
			printf("You guessed incorrectly. Enter 1 to exit or any other character to guess again.\n");
			fgets (buffer_exit, 256, stdin);
			endgame = atoi (buffer_exit);
		} 
	}
	
}
