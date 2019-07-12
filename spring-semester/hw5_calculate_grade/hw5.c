#include<stdio.h>

double adjScore(int score)
{
	double adj_score = 0.0; 
	double sqrt_score = 1.0;

	if(score != 0)
	{
		int i;
		for(i = 0; i < 10; i++)
		{	
			sqrt_score = 0.5*(sqrt_score+(score/sqrt_score));
		}
	}
	else
	{
		sqrt_score = 0;		
	}

	adj_score = sqrt_score*10;
	return adj_score;
}

double getAvg(double score[], int total_array)
{
	double avg = 0.0;
	int i;
	for(i=0; i<total_array; i++)
	{
		avg = avg + score[i];
	}
	avg = avg/total_array;
	return avg;
}

double getMax(double score[], int total_array)
{
	double max = 0.0;
	int i;
	for(i=0; i<total_array; i++)
	{
		if(score[i] > max)
		{	
			max = score[i];
		}
	}
	return max;
}

double getMin(double score[], int total_array)
{
	double min = 100.0;
	int i;
	for(i=0; i<total_array; i++)
	{
		if(score[i] < min)
		{
			min = score[i];
		}
	}
	return min;
}

int main(void)
{
	
	double c_score[1000], p_score[1000], l_score[1000], avg_score[1000];
	int C_score, P_score, L_score;
	int total = 0;
	int i, j;
	for(i=0; i<999; i++)
	{
		c_score[i] = 0;
		p_score[i] = 0;
		l_score[i] = 0;
	}
	
	while(scanf("%d%d%d",&C_score ,&P_score ,&L_score) != EOF)
	{
			c_score[total] = adjScore(C_score);
			p_score[total] = adjScore(P_score);
			l_score[total] = adjScore(L_score);
			total++;
	}

	int order[total];
	/*average score*/
	for(i=0; i<total; i++)
	{
		avg_score[i] = (c_score[i] + p_score[i] + l_score[i])/3;
		order[i] = i;
	}
	

	for(j=0; j<total; j++)
	{
		for(i=0; i<(total-j); i++)
		{
			if(avg_score[i+1] > avg_score[i])
			{	
				double temp_1 = avg_score[i];
				avg_score[i] = avg_score[i+1];
				avg_score[i+1] = temp_1;

				int temp_2 = order[i];
				order[i] = order[i+1];
				order[i+1] = temp_2;
			}
		}
	}

	printf("ID      |Calculus|Programming|Linear Algebra|Average\n");
	printf("-----------------------------------------------------------\n");
	for(i=0; i<total; i++)
	{
		printf("%d\t| %.1lf   | %.1lf      | %.1lf         | %.1lf  \n"
		,order[i] ,c_score[order[i]], p_score[order[i]], l_score[order[i]], avg_score[i]);		
	}	
	printf("-----------------------------------------------------------\n");
	printf("Max     | %.1lf   | %.1lf      | %.1lf\n",getMax(c_score,total),getMax(p_score,total),getMax(l_score,total));
	printf("Min     | %.1lf   | %.1lf      | %.1lf\n",getMin(c_score,total),getMin(p_score,total),getMin(l_score,total));
	printf("Avg     | %.1lf   | %.1lf      | %.1lf\n",getAvg(c_score,total),getAvg(p_score,total),getAvg(l_score,total));
	return 0;	
}
