#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

//count the number of experiments per scientist 
int countNumOfExperiemnts(char x1[])
{
	int i=0;
	int numOfOccurences=0;
	for(i=0;i<strlen(x1);i++)
	{
		if(x1[i]==',')
			{numOfOccurences++;}
	}
	return numOfOccurences;
}

int main(int argc, char *argv[])
{
	FILE *file=fopen(argv[1],"r");
	if(file !=NULL)
	{
		char line[1000]; // will hold the info for one line
		int records_counter=0;
		//count the number of scientists in the text file
		while(fgets(line,sizeof line,file)!= NULL)
		{
			records_counter++;
		}
		struct record *myRecords=(struct record*)calloc(records_counter, sizeof(struct record));
		rewind(file);
		records_counter=0;
		int experiments_counter=0;
		while(fgets(line,sizeof line,file)!= NULL)
		{
			myRecords[records_counter].num_of_experiments=countNumOfExperiemnts(line);
			char *token;
			token = strtok (line,",");
			strcpy(myRecords[records_counter].name,token);
			myRecords[records_counter].experiments= (int*)calloc(myRecords[records_counter].num_of_experiments,sizeof(int));
			token = strtok (NULL, ",");
			//get the experiemnts and store it for every scientist			 	
			  while (token != NULL)
			  {
			  	myRecords[records_counter].experiments[experiments_counter]=atoi(token);
			  	experiments_counter++;
			    token = strtok (NULL, ",");
			  }
			experiments_counter=0;
			records_counter++;
		}
		//get the average and print it out for each scietist 
		for(int i=0;i<records_counter;i++)
		{
			int sum=0;
			printf("%s ",myRecords[i].name);
			for(int j=0;j<myRecords[i].num_of_experiments;j++)
				sum+=myRecords[i].experiments[j];
			printf("%.2f\n",sum/(float)myRecords[i].num_of_experiments);

		}
		fclose(file);
	}
	else
	{
		perror(argv[1]);
	}
	return 0;
}

