#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//check the user if he types quit
int isExit(char *str)
{
	if(str==NULL)
		return 0;
	if(strcasecmp(str,"QUIT")==0)
		return 1;
	return 0;
}

//check if the user enters the set prompt command correctly with the argument
int isSetPrompt(char *str)
{
	char temp[100];
	strcpy(temp,str);
	char *token = strtok (temp," ");
		if(token==NULL)
			return 0;
		if(strcasecmp(token,"SET")!=0 )
			return 0;
	token = strtok (NULL, " ");
		if(token==NULL)
			return 0;
		if(strcasecmp(token,"PROMPT")!=0)
			return 0;
	token = strtok (NULL, " ");
		if(token==NULL)
			return 0;
	return 1;
}
int main(void)
{
	char prompt[100]="$SAM: ";
	char *input=(char *)malloc(sizeof(char)*100);
	printf("%s",prompt);
	gets(input);
	while(!isExit(input))
	{
		 if(isSetPrompt(input))
		{
			char *token = strtok (input," ");
			token = strtok (NULL, " ");
			token = strtok (NULL, " ");
			strcat(token," ");
			strcpy(prompt,token);
		}
		else
		{
			system(input);
		}
		printf("%s",prompt);
		gets(input);
	}
}
