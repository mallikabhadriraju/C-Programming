# include <limits.h>

# include <string.h>

# include <stdio.h>


# define NO_OF_CHARS 256


int max (int a, int b)
 { 
return (a > b)? a: b; 
}


void fillhashtable( char *str, int size, 
int hashtable[NO_OF_CHARS])

{
	
int i;
	
for (i = 0; i < NO_OF_CHARS; i++)
		
hashtable[i] = -1;

	
for (i = 0; i < size; i++)
		
hashtable[(int) str[i]] = i;

}


void search( char *txt, char *pat)

{
	
int m = strlen(pat);
	
int n = strlen(txt);

	
int hashtable[NO_OF_CHARS];

	
fillhashtable(pat, m, hashtable);

	
int s = 0; 
	
while(s <= (n - m))
	
{
		
int j = m-1;

		
while(j >= 0 && pat[j] == txt[s+j])
			
j--;

		
if (j < 0)
		
{
			
printf("\n pattern occurs at shift = %d", s);

			
s += (s+m < n)? m-hashtable[txt[s+m]] : 1;

		
}

		
else
			
s += max(1, j - hashtable[txt[s+j]]);
	
}

}


int main()

{
	
char txt[] = "ABAAABCD";
	char pat[] = "ABC";
	
search(txt, pat);
	
return 0;

}
