#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return smallest of 3 inputted values
#define MIN(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define SIZE(a) sizeof(a) / sizeof(a[0])

int distance(char *str1, char *str2)
{
	size_t s1 = strlen(str1);
	size_t s2 = strlen(str2);
	if (s1 == 0) { return 0; }
	if (s2 == 0) { return 0; }
	
	int matrix1[s2]; // Previous row of distances
	int matrix2[s2]; // Current row of distances
	
	int i, j;
	for (i=0; i < s2; i++)
	{
		matrix1[i] = i;
	}
	
	for (i=0; i < s1-1; i++)
	{
		matrix2[0] = i + 1;

		for (j=0; j < s2-1; j++)
		{
			int cost = (str1[i] == str2[j]) ? 0 : 1;
			matrix2[j+1] = MIN(matrix2[j] + 1, matrix1[j+1] + 1, matrix1[j] + cost);
		}
		
		// Copy matrix2 into matrix1
		for (j=0; j < SIZE(matrix2); j++)
		{
			matrix1[j] = matrix2[j];
		}
	}
	
	return matrix2[s2-1];
}

int main()
{
	char word1[] = "apple", word2[] = "aple";
	printf("%i", distance(word1, word2));
	return 0;
}
