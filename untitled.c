#include <stdio.h>
#include <string.h>

int main()
{	int t;
	printf("Number of tests\n");
	scanf("%d", &t);

	int n[t],k[t];
	for (int i = 0; i < t; ++i)
	{
		printf("Test %d, N value =\n",(i+1));
		scanf("%d", &n[i]);

		printf("Test %d, K value =\n", (i+1));
		scanf("%d", &k[i]);
	}

	int a[t][100000];
	//lay the first set of array values.
	for (int i = 0;  i< t; ++i)
	{ 	
		for (int j = 0; j < n[i]; ++j)
		{
		a[i][j] = j;
		}
	}

	printf("Arrangement before it starts\n");
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < n[i]; ++j)
			{
				printf("%d",a[i][j]);
			} 
		printf("\n");
	}

	printf("Manipulation starts here:\n");
	//Re-Arrangement
	for (int k = 0; k < t; ++k)
	{
		printf("The %d Test\n",k );
			
			for (int i = 0; i < n[k]; ++i)
			{		
				for (int j = 0; j < ((n[k]-i)/2); ++j)
				{	
						int t = a[k][i+j];
						a[k][i+j] = a[k][n[k]-1-j];
						a[k][n[k]-1-j] = t;
				}

				//Print to console
				for (int i = 0; i < n[k]; ++i)
				{
					printf("%d",a[k][i]);
				} 
				printf("\n");
			}
	}
	
	// Search for K and print the index out
	for (int j = 0; j < t; ++j)
	{
		for (int i = 0; i < n[j]; ++i)
		{
			if (a[j][i] == k[j])
			{
			printf("Value to search for = %d\n", k[j]);
			printf("Test %d index is at %d\n", (j+1),i);
			}
		}
	}

	return 0;
}


