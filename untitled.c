#include <stdio.h>

int main()
{	int t;
	printf("Number of tests\n");
	scanf("%d", &t);

	int n[t],k[t];
	for (int i = 0; i < t; ++i)
	{
	printf("Test %d, N value =\n",i);
	scanf("%d", &n[i]);

	printf("Test %d, K value =\n", k);
	scanf("%d", &k[t]);
	}

	int a[t][n];
	
	//lay the first set of array values.
	for (int i = 0;  i< t; ++i)
	{ 	
		for (int j = 0; j < n; ++j)
		{
		a[i][j] = j;
		}
	}


	printf("Arrangement before it starts\n");
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < n; ++j)
			{
				printf("%d",a[i][j]);
			} 
		printf("\n");
	}


	printf("Manipulation starts here:\n");
	//Re-Arrangement
	for (int i = 0; i < n; ++i)
	{		
		for (int j = 0; j < ((n-i)/2); ++j)
		{	
				int t = a[i+j];
				a[i+j] = a[n-1-j];
				a[n-1-j] = t;
		}

		//Print to console
		for (int i = 0; i < n; ++i)
		{
		printf("%d",a[i]);
		} printf("\n");

	}

	// Search for K and print the index out
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == k)
		{
			printf("index is at %d\n", i);
		}
	}

	return 0;
}


