#include<stdio.h>
int main()
{
		int c;
		int tc = 0, oc = 0;						/* tc = total characters 
							   					   oc = other characters */
		int g, h, i, j;							/* for function variables */
		int digit[10], alphabet[26];
			
		
		for(g = 0; g<=9; g++)					/*assign array an initial value*/
		{
			digit[g] = 0;		
		}
		for(h = 0; h<=25; h++)
		{
			alphabet[h] = 0;
		}

		while((c = getchar()) != EOF)
		{
			tc++;

			if(c>='0' && c<='9')
			{
				digit[c-'0']++;
			}
		    else if(c>='A' && c<='Z')
			{
				alphabet[c-'A']++;
			}
		    else if(c>='a' && c<='z')
			{
				alphabet[c-'a']++;
			}
			else
			{				
				oc++;
			}
		}
		
		printf("Total characters : %d\n", tc);
		printf("Other character : %d\n", oc);
		
		if(tc>0)
		{
			printf("\n--number--\n");
			for(i = 0; i < 10; i++)
			{
				printf("%d : %d , %.3f\n", i, digit[i], digit[i]*1.0/tc);	
			}

			printf("\n--alphabet--\n");
			for(j = 'a'; j <= 'z'; j++)
			{
				printf("%c : %d , %.3f\n", j, alphabet[j-'a'], alphabet[j-'a']*1.0/tc);
			}
		}
        else
        {
        	printf("Please Input a Character");	
        }
}
