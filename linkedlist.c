#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
    char scan[MAX_LENGTH]; 
	NODE *head = NULL; //store the head of the linked list
	NODE *current_ptr = NULL; //store the current node looking at 
	#ifdef ENGLISH
		printf("Welcome to the infinite string storage program.\n");
	#endif
	#ifdef FRENCH
		printf("Bienvenue to the infinite string storage program.\n");
	#endif
	while(1)
	{
		#ifdef ENGLISH
			printf("Please enter a single word: ");
		#endif
		#ifdef FRENCH
			printf("S'ilvous plait enter a single word: ");
		#endif
		scanf("%s",scan);
		if(strcmp(scan,"***END***") == 0)
		{ 
			current_ptr = head; 
			while(current_ptr != NULL){
				printf("%s\n", (*current_ptr).value); 
				current_ptr=(*current_ptr).next; 
			}
			return 0;
		}
			if(head==NULL)
		{
			//if the linked list wasn't created, create one
			head=(NODE *)malloc(sizeof(NODE));
			strcpy(head->value,scan);
			head->next = NULL;
			current_ptr = head;
		}
		else
		{ 
			current_ptr->next = (NODE *)malloc(sizeof(NODE)); //create a new node
			strcpy(current_ptr->next->value,scan); 
			current_ptr=current_ptr->next; //move to the next node
			
		}
	}
}