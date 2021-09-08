#include "Pushswap.h"

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
stack1_t *swapfirst(stack1_t *head)
{
	int i;

	i = head->next->value;
	head->next->value = head->value;
	head->value = i;
	return (head);

}

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
