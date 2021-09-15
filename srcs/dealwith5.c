#include "Pushswap.h"

void fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stack)
{
	stack1_t *tmp2;
	int i;

	i = 0;
	givenode(head, head2, 1, stack);
	if (size == 5)
		givenode(head, head2, 1, stack);
	triplechar(head, stack);
	givenode(head2, head, 0, stack);
	tmp2 = *head;
	while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
	{
		swapfirst(*head, 0, stack);
		*head = (*head)->next;
		i++;
	}
	while ((*head)->prev != NULL)
		*head = (*head)->prev;	

	if (size == 5)
	{
		givenode(head2, head, 0, stack);
		if ((*head)->value > tmp2->value && i == 3)
		{
			toptobottom(head, 0, stack);
		}
		else while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
		{
			swapfirst(*head, 0, stack);
			*head = (*head)->next;
		}
		while ((*head)->prev != NULL)
		*head = (*head)->prev;	

	}
}
