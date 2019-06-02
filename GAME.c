
// Count the number of ways to reach a given score in a game  where a move can earn 2 or 4 or 6

#include <stdio.h>

#include <conio.h>

// Returns number of ways to reach score n

int count(int score)
{
	int i;

	int *count = (int*) malloc( ( score / 2 + 1 ) * sizeof(int) );

	for( i=0; i<=score; i++ )

		count[i] = 0;

	count[0] = 1, count[1]=1, count[2]=2;

	for( i=3; i<=score/2; i++ )
	{
		count[i] = count[i-1] + count[i-2] + count[ i-3 ];
	}

	return count[score / 2];
}


// Driver program

void main( )
{
	int score = 6;

	clrscr();

	printf("\n\n  The number of ways to the score %d : %d", score, count(score));


	score = 8;

	printf("\n\n  The number of ways to the score %d : %d", score, count(score));

	getch();
}

