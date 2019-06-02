// weighted job scheduling

#include<stdio.h>

#include<conio.h>
 
// A job has start time, finish time and profit.

struct job
{
	int start, finish, profit;
};


typedef struct job Job;


// Find the latest job (in sorted array) that doesn't conflict with the job[i]

int latestNonConflict(Job jobs[], int i)
{
	int j;

	for ( j=i-1; j>=0; j--)
	{
		if ( jobs[j].finish <= jobs[i].start)

			return j;
	}
	return -1;
}


void sort( Job *jobs, int n )
{
	int i, j;

	Job t;

	for( i=0 ; i<n-1 ; i++ )
	{
		for( j=0 ; j<n-(i+1) ; j++ )
		{
			if( jobs[j].finish > jobs[j+1].finish )
			{
				t = jobs[j];

				jobs[j]=jobs[j+1];

				jobs[j+1]=t;
			}
		}
	}
}

int max( int x, int y )
{
	return( x > y ? x : y );
}

// The main function that returns the maximum possible profit from given array of jobs

int findMaxProfit(Job *jobs, int n)
{

	int i, profit, l;

	// Create an array to store solutions of subproblems.  table[i]

	// stores the profit for jobs till jobs[i] (including jobs[i])


	int *table = (int*) malloc( n * sizeof(int) );


	// Sort jobs according to finish time

	sort( jobs, n );


	table[0] = jobs[0].profit;

	// Fill entries in M[] using recursive property

	for ( i=1; i<n; i++)
	{
		// Find profit including the current job

		profit = jobs[i].profit;

		l = latestNonConflict( jobs, i);

		if (l != -1)

			profit += table[l];

		// Store maximum of including and excluding

		table[i] = max( profit, table[i-1]);
	}

	return table[n-1];
}

// Driver program

void main()
{
	Job jobs[] = {{1, 4, 100}, {3, 4, 50}, {3, 6, 300}, {1, 2, 20}};

	int n = sizeof(jobs)/sizeof(jobs[0]);

	clrscr();

	printf( "\n\n   The optimal profit : %d ", findMaxProfit( jobs, n) );

	getch();
}