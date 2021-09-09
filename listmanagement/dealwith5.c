#include "Pushswap.h"

void fivechar(stack1_t **head, stack1_t **head2, int size)
{
	stack1_t *tmp2;
	int i;

	i = 0;
	givenode(head, head2);
	if (size == 5)
		givenode(head, head2);
	triplechar(head);
	givenode(head2, head);
	tmp2 = *head;
	while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
	{
		swapfirst(*head);
		*head = (*head)->next;
		i++;
	}
	while ((*head)->prev != NULL)
		*head = (*head)->prev;	

	if (size == 5)
	{
		givenode(head2, head);
		if ((*head)->value > tmp2->value && i == 3)
		{
			toptobottom(head);
		}
		else while ((*head)->next != NULL && (*head)->next->value < (*head)->value)
		{
			swapfirst(*head);
			*head = (*head)->next;
		}
		while ((*head)->prev != NULL)
		*head = (*head)->prev;	

	}
}
