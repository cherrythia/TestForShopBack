#include <stdio.h>
#include <string.h>

/*----------------------Assumption----------------------------*/
//1. The Macbook pro will break at breaklvl.
//2. Macbook pro drop below breaklvl will not break. 
//3. Macbook pro drop at breaklvl and above breaklvl will break.

#define breaklvl 31

/*----------------------Method-------------------------------*/
//We test for the breaklvl at different intervals.
//1. Test at every 10 level. 
//2. Minus 5 level and test.
//3. test at every single level.

//Singular level test at every floor
int singular(test,count){
	count++;
	if (test< breaklvl)
	{	
		test +=1;
		singular(test,count);
	}
	else if (test > breaklvl)
	{	
		test -= 1;
		singular(test,count);
	}
	else{ //when they are equal print this
		
		printf("Breaking level is found!\n");
		printf("Macbook1 breaks at = %d\n", test);
		printf("Macbook2 survived at = %d\n", (test-1) );
		printf("The number of times it has dropped %d\n", count);
	}
	return 1;
}

//Interval testing - every 10th floor
int intervaldrop(test,count){
	++count;
	
	if(test < breaklvl)
	{	
		test += 10; 					
		intervaldrop(test,count);
	}
	else{
		test -= 5;					//minus 5 floors and test
		count++;
		singular(test,count);
	}
	return 1;
}


int main()
{	
	int count = 0;
	int test = 10; 					//test starts from the 10th floor
	intervaldrop(test,count);

	return 0;
}