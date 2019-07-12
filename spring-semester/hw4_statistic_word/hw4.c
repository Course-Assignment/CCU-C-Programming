#include<stdio.h>

int main()
{
	int c = 0;
	int ta, tw, twc;			/*ta  = total alphabet*/
								/*tw  = total word*/	
								/*twc = total word count*/
	int i, j;
	tw = ta = twc = i = j = 0;

	float avg = 1.0/26;
	int alphabet[26] = {0}, leter[26] = {0};
	char word[1000][50];
	
    while((c = getchar()) != EOF)
	{	
		if(c >= 'a' && c <= 'z')
		{
			alphabet[c-'a']++;
			ta++;
			word[tw][i] = c;
			i++;
		}
		else if(c >= 'A' && c <= 'Z')
		{
			alphabet[c-'A']++;
			ta++;
			word[tw][i] = c;
			i++;
		}
		else if(c== ' ' || c== '\n' || c=='\t')				
		{	
			word[tw][i] = '\0';								/*'\0' is macked to represent the end of a string*/	
			i = 0;											/*first char load in word[0][0] and second in word[0][1].etc*/
			tw++;											/*first word load in word[0] and second in word[1] .etc*/
		}
		else
		{
			word[tw][i] = c;
			i++;
		}
	}
																
	for(i = 0; i < tw; i++)									/*To count the total words*/						
	{
		char m = word[i][0];
		if(m >= 'a' && m <= 'z' || m >= 'A' && m <= 'Z')
		{
	    	twc++;				
		}
	}
	
	printf("\n[A]\n");
	printf("Word count: %d\n", twc);
	printf("--Words--\n");

	for(i = 0; i < tw; i++)									/*Print each word*/
    {
    	char n = word[i][0];							
    	if(n >= 'a' && n <= 'z' || n >= 'A' && n <= 'Z')	/*If the first char of each string is alphabet print it*/
		{
			printf("%s\n", word[i]);		
		}
    }
	
	printf("\n[B]\n");
	printf("Total : %d\n", ta);
	printf("--Alphabet--\n");

	for(i = 'a'; i <= 'z'; i++)								/*Print 'a' to 'z' , occurrences ,frequency*/
	{		
		leter[i-'a'] = i;
		if(ta != 0)
		{
			printf("%c : %d , %.3f\n", i, alphabet[i-'a'], alphabet[i-'a']*1.0/ta);
		}
		else
		{
			printf("%c : %d , %.3f\n", i, alphabet[i-'a'], 0.0);
		}
	}
	
	if(ta != 0)
	{
		printf("Avg = %.3f\n", avg);
	}
	else
	{
		printf("Avg = %.3f\n", 0.0);
	}


	for(j = 0; j < 25; j++)									/*Bublble sort to combination from smalleat to largest*/
	{
		for(i = 0; i < (25 - j); i++)
		{
			if(alphabet[i] > alphabet[i+1])
			{
				int temp_1 = alphabet[i+1];
				alphabet[i+1] = alphabet[i];
				alphabet[i] = temp_1;

				int temp_2 = leter[i+1];
				leter[i+1] = leter[i];
				leter[i] = temp_2;
			}
		}
	}

	if(ta != 0)
	{
		printf("Max: %c: %d %.3f\n", leter[25], alphabet[25], alphabet[25]*1.0/ta);			/*Print Max & Min*/
		printf("Min: %c: %d %.3f\n", leter[0], alphabet[0], alphabet[0]*1.0/ta);
	}
	else
	{
		printf("There are no Max & Min in this text, each of count is zero\n");			
	}

}
