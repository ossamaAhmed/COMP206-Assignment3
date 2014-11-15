#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isExit(char *str)
{
	if(strcasecmp(str,"QUIT")==0)
		return 1;
	return 0;
}
int isSetPrompt(char *str)
{
	char temp[100];
	strcpy(temp,str);
	char *token = strtok (temp," ");
		if(strcasecmp(token,"SET")!=0 )
			return 0;
	token = strtok (NULL, " ");
		if(strcasecmp(token,"Prompt")!=0)
			return 0;
	return 1;
}
int main(void)
{
	char *reserved1="SET PROMPT";
	char *reserved2="QUIT";
	char prompt[100]="$SAM: ";
	char *input=(char *)malloc(sizeof(char)*100);
	printf("%s",prompt);
	gets(input);
	if(input[0]=='\n')
	{
		return 0;
	}
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
