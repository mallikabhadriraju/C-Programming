// Cutting a rod

#include<stdio.h>

#include<conio.h>

#include<limits.h>

// A utility function to get the maximum of two integers


int max(int x, int y)
{
	return ( x > y )? x : y;
}


/* Returns the best obtainable price for a rod of length n and price[] as prices of different pieces */

int cutRod(int prices[], int n)
{
	int i, j;

	int maxval;

	int *values = (int*) malloc( ( n + 1 ) * sizeof(int) );

	values[0] = 0;

	// Build the table val[] in bottom up manner and return the last entry from the table

	for (i = 1; i<=n; i++)
	{
		maxval = INT_MIN;

		for ( j = 0; j < i; j++)

			maxval = max(maxval, prices[j] + values[i-j-1]);

		values[i] = maxval;
	}

	return values[n];
}

/* Driver program to test above functions */

void main()
{
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};

	int size = sizeof(prices)/sizeof(prices[0]);

	clrscr();

	printf("\n\n  Maximum Obtainable Value : %d", cutRod(prices, size));
    
	getch();
}