#include<stdio.h>

int main()
{
		int c;
		int tc, tl, tn, tv; 	/*tc = total character
								  tl = total line
							  	  tn = total number
							  	  tv = total vowel*/
		tc = tl = tn = tv = 0;

		while((c = getchar()) != EOF)
		{
				tc++;

				if(c=='\n')
				{
                	tl++;
				}
				if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
				{
					tn++;
				}
				if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
				{
					tv++;		
				}
		}
        
        printf("Total characters: %d\n",tc);
        printf("Total row: %d\n",tl);
        printf("Number: %d\n",tn);
        printf("Vowel: %d\n",tv);

}


