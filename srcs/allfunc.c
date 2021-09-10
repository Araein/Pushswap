#include <stdlib.h>
#include <stdio.h>

struct stack1 {

	int value;
	struct stack1 *next;
	struct stack1 *prev;
};
typedef struct stack1 stack1_t;


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
	result->prev = NULL;
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
		if (j > 1)
			head->prev = tmp;
		head = tmp;
	}
	return (head);
}

/*SWAP 2 FIRST ELEMENT OF LIST*/

stack1_t *swapfirst(stack1_t *head)
{
	int i;

	i = head->next->value;
	head->next->value = head->value;
	head->value = i;
	return (head);

}
/* GIVE FIRST ELEMENT OF A LIST TO ANOTHER ONE*/

void givenode( stack1_t **head,  stack1_t **head2)
{
	stack1_t *tmp;

	tmp = *head;
	(*head)->next->prev = NULL;
	*head = (*head)->next;    /*lignes inversees attention*/


	tmp->next = *head2;
	(*head2)->prev = tmp;
	*head2 = tmp;

}

int countelem (stack1_t *head)
{
	int i;
	
	if (head == NULL)
		return (0);
	i = 1;
	while (head->next != NULL)
	{
		i++;		
		head = head->next;
	}
	return i;
}

void toptobottom(stack1_t **head)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	
	tmp = *head;
	tmp2 = (*head)->next;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	while ((*head)->next != NULL)
		*head = (*head)->next;	
	tmp->prev = *head;
	tmp->next = NULL;
	(*head)->next = tmp;
	*head = tmp2;
}


void bottomtotop(stack1_t **head)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	
	while ((*head)->next != NULL)
		*head = (*head)->next;
	tmp2 = *head;
	tmp = (*head)->prev;
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	tmp->next = NULL;
	tmp2->prev = NULL;
	(*head)->prev = tmp2;
	tmp2->next = *head;
	*head = tmp2;
}

/*QTTENTION AJOUTER EXCEPTION EN CAAS DE LISTES VIDES OU QUASI VIDES*/
int main ()
{
	stack1_t *head;
	stack1_t *head2;
	stack1_t *head3;
	head = generatestack(10);
	
	head2 = generatestack(10);
	head3 = generatestack(10);

	bottomtotop(&head2);
	toptobottom(&head3);
	givenode(&head, &head2);

	printf("\n--------------- head :\n");
	printlist(head);
//	printf("\n head a %d elem", countelem(head));
	printf("\n--------------- head2 bottomtotop :\n");
	printlist(head2);
	printf("\n--------------- head3 toptobottom :\n");
	printlist(head3);


//	printf("\n head2 a %d elem", countelem(head2));


	return (0);
}








