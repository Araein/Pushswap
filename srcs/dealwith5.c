#include "Pushswap.h"

void fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stack)
{
	stack1_t *tmp2;
//	stack1_t *tmp;
	int i;

	i = 0;
	givenode(head, head2, 1, stack);
	if (size == 5)
		givenode(head, head2, 1, stack);

	triplechar(head, stack);

	givenode(head2, head, 0, stack);
	tmp2 = *head;

/*MARCHE AUE SI SWAP DE POINTEURS*/
	if ((*head)->value > (*head)->next->next->next->value)
	{
			toptobottom(head, 0, stack);
	}
	else if (/*tmp2->value < tmp2->prev->value && */tmp2->value > tmp2->next->value)
	{
	//	printf("first = %d // next = %d\n", tmp2->value, tmp2->next->value);
		swapfirst(head, 0, stack);
	//	printf("first = %d // next = %d", tmp2->value, tmp2->next->value);
		if (/*tmp2->value < tmp2->prev->value && */tmp2->value > tmp2->next->value)
		{
			toptobottom(head, 0, stack);
			swapfirst(head, 0, stack);
			bottomtotop(head, 0, stack);
		}
	}
	
	
/*	while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
	{
		swapfirst(*head, 0, stack);
		*head = (*head)->next;
		i++;
	}
	while ((*head)->prev != NULL)
		*head = (*head)->prev;	
*/
	if (size == 5)
	{
		givenode(head2, head, 0, stack);
		if ((*head)->value > (*head)->next->next->next->next->value/* && i == 3*/)
		{
			toptobottom(head, 0, stack);
		}
		else while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
		{
			swapfirst(head, 0, stack);
			*head = (*head)->next;
		}
		while ((*head)->prev != NULL)
		*head = (*head)->prev;	

	}
}
