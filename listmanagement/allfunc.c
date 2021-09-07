#include <stdlib.h>
#include <stdio.h>

struct stack1 {

	int value;
	struct stack1 *next;
};
typedef struct stack1 stack1_t;
/*
struct stack2 {

	int value;
	struct stack2  *next;
};
typedef struct stack2 stack2_t;
*/





/* PRINT LIST*/
void printlist (stack1_t *head)
{
	stack1_t *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

/*CREATE NODE DYNAMICALLY*/

stack1_t *createnode (int value)
{
	stack1_t *result = malloc(sizeof(stack1_t));
	result->value = value;
	result->next = NULL;
	return (result);
}

stack1_t *generatestack(int i)
{

	stack1_t *head;
	stack1_t *tmp;
	int j;
	
	head = NULL;
	j = 0; 
	tmp = createnode(j);
	while (j < i)
	{
		j++;
		tmp = createnode(j);
		tmp->next = head;
		head = tmp;
	}
	return (head);
}

/*SWAP 2 FIRST ELEMENT OF LIST*/

stack1_t *swapfirst(stack1_t *head)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	int i;

	tmp = head->next;
	tmp2 = head;	
	i = tmp2->value;
    tmp2->value = tmp->value;
	tmp->value = i;

	return (head);

}
/* GIVE FIRST ELE;ENT OF A LIST TO ANOTHER ONE*/

void givenode( stack1_t **head,  stack1_t **head2)
{
	stack1_t *tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = *head2;
	*head2 = tmp;
}


int main ()
{
	stack1_t *head;
	stack1_t *head2;
//	stack1_t *tmp;

	head = generatestack(5);
	head2 = swapfirst(generatestack(20));
	
/*	printf("\n--------------- head :\n");
	printlist(head);
	printf("\n--------------- head2 :\n");
	printlist(head2);
*/

	
	givenode(&head,  &head2);

/*		
	tmp = head2;
	head2 = head2->next;
	tmp->next = head;
	head = tmp;
*/	

	//printlist(head2);
	
	printf("\n--------------- head :\n");
	printlist(head);
	printf("\n--------------- head2 :\n");
	printlist(head2);



	return (0);
}








