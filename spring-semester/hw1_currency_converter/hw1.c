#include <stdio.h>
#include <stdlib.h>

int main()
{
   	double  input, output;
	while(1)
	{	
		printf("input:");
  	    scanf("%lf",&input);
  	    if(input==0)
		{		
			printf("End\n");
			break;
		}
		output=input*30.48;		
	   	printf("output:%lf\n",output);
	}
}
