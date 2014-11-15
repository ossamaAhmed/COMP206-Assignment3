#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

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

int main(void)
{
	char filename[]="file.txt";
	FILE *file=fopen(filename,"r");
	if(file !=NULL)
	{
		char line[1000];
		int counter=0;
		while(fgets(line,sizeof line,file)!= NULL)
		{
			//strcopy(myRecords[counter].myLine,line);
			counter++;
		}
		//printf("%d\n",counter);
		struct record *myRecords=(struct record*)calloc(counter, sizeof(struct record));
		rewind(file);
		counter=0;
		int counter2=0;
		while(fgets(line,sizeof line,file)!= NULL)
		{
			int num=countNumOfExperiemnts(line);
			char *token;
			token = strtok (line,",");
			strcpy(myRecords[counter].name,token);
			printf("%s\n",myRecords[counter].name);
			printf("%d\n",num);
			myRecords[counter].experiments= (int*)calloc(num,sizeof(int));
			token = strtok (NULL, ",");			 	
			  while (token != NULL)
			  {
			  
			  	//printf("%s %d %s %d \n","counter",counter,"counter2",counter2);
			  	myRecords[counter].experiments[counter2]=atoi(token);
			  	printf ("%d\n",myRecords[counter].experiments[counter2]);
			  	counter2++;
			    token = strtok (NULL, ",");
			  }
			  counter2=0;
			//fprintf(stdout, "%s",line);
			counter++;
		}
		fclose(file);
		 //printf ("%d\n",myRecords[0].experiments[4]);
	}
	else
	{
		perror(filename);
	}
	return 0;
}

