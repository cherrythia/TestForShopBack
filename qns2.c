#include <stdio.h>
#include <string.h>

//define the floor that the macbook pro will break
int breaklvl = 22;

//Global variable
int count = 0; 

//Singular testing = every single floor
int singulardrop(test) 
{
	++count;
	test -= 1;
	if(test != breaklvl){
		return singulardrop(test);
	}

	else{
		printf("Breaking point is found!!\n");
		printf("Macbook1 breaks at = %d\n", test);
		printf("Macbook2 survived at = %d\n", (test-1) );
		printf("The number of times it has dropped %d\n", count);
	}

	return 1;
}

//Interval testing - every 10th floor
int intervaldrop(test){
		
	++count;
	
	if(test < breaklvl)
	{	
		test += 10; 				//interval of tenth
		return intervaldrop(test);
	}
	else{
		singulardrop(test);
	}

	return 1;
}


int main()
{	
	int test = 10; //test starts from the 10th floor
	intervaldrop(test);

	return 0;
}