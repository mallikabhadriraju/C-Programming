
// Collect maximum coins in grid using two traversals

#include<stdio.h>

#include<conio.h>

#include<limits.h>

#define ROWS 5

#define COLS 5

// checks whether a given input is valid or not

int isValid(int x, int y1, int y2)
{
	return (x >= 0 && x < ROWS && y1 >=0 && y1 < COLS && y2 >=0 && y2 < COLS);
}

int max( int x, int y )
{
	return( x > y ? x : y );
}

// Driver function to collect max value

int getMaxUtil(int coins[ROWS][COLS], int mem[ROWS][COLS][COLS], int x, int y1, int y2)
{
	int answer, temp;

	// if P1 or P2 is at an invalid cell

	if (!isValid(x, y1, y2))

		return INT_MIN;

	// if both traversals reach their destinations

	if (x == ROWS-1 && y1 == 0 && y2 == COLS-1)

		return (y1 == y2)? coins[x][y1]: coins[x][y1] + coins[x][y2];

	// If both traversals are at last row but not at their destination

	if (x == ROWS-1)

		return INT_MIN;

	// If subproblem is already solved

	if (mem[x][y1][y2] != -1)

		return mem[x][y1][y2];

	// Initialize answerwer for this subproblem

	answer = INT_MIN;

	// this variable is used to store gain of current cell(s)

	temp = (y1 == y2)? coins[x][y1]: coins[x][y1] + coins[x][y2];


	/* Recur for all possible cases, then store and return the one with max value */

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1, y2-1));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1, y2+1));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1, y2));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1-1, y2));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1-1, y2-1));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1-1, y2+1));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1+1, y2));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1+1, y2-1));

	answer = max(answer, temp + getMaxUtil(coins, mem, x+1, y1+1, y2+1));

	return (mem[x][y1][y2] = answer);
}

// This is mainly a wrapper over recursive function getMaxUtil().
// This function creates a table for memoization and calls
// getMaxUtil()

int geMaxCollection(int coins[ROWS][COLS])
{
	// Create a memoization table adnd initialize all entries as -1

	int mem[ROWS][COLS][COLS];

	memset(mem, -1, sizeof(mem));

	// Calculation maximum value using memoization based function getMaxUtil()

	return getMaxUtil(coins, mem, 0, 0, COLS-1);
}

// Driver program to test above functions

void main()
{
	int coins[ROWS][COLS] = { 	{ 3, 5, 7, 3, 2},
					{ 6, 7, 2, 4, 6},
					{ 1, 20, 40, 20, 7},
					{ 3, 4, 1, 20, 5},
					{ 4, 3, 5, 2, 1 }
		    };

	clrscr();

	printf( "\n\n  Maximum collection : %d ", geMaxCollection( coins ) );

	getch();
}