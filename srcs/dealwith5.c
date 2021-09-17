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


if((*head)->value > (*head)->next->value)
{
	if ((*head)->value > (*head)->next->next->next->value)
	{
			toptobottom(head, 0, stack);
	}
	else if (tmp2->value > tmp2->next->value)
	{
		swapfirst(head, 0, stack);
		if (tmp2->value > tmp2->next->value)
		{
			toptobottom(head, 0, stack);
			swapfirst(head, 0, stack);
			bottomtotop(head, 0, stack);
		}

	}
}
	if (size == 5)
	{
		givenode(head2, head, 0, stack);		
			tmp2 = *head;

		if ((*head)->value > (*head)->next->value)
		{
			if ((*head)->value > (*head)->next->next->next->next->value)
			{
					toptobottom(head, 0, stack);
			}
			else if (tmp2->value > tmp2->next->value)
			{
				swapfirst(head, 0, stack);
				if (tmp2->value > tmp2->next->value)
				{
					toptobottom(head, 0, stack);
					swapfirst(head, 0, stack);
					bottomtotop(head, 0, stack);
				}
				if (tmp2->next != NULL && tmp2->value > tmp2->next->value)
				{
					toptobottom(head, 0, stack);
					toptobottom(head, 0, stack);
					swapfirst(head, 0, stack);
					bottomtotop(head, 0, stack);
					bottomtotop(head, 0, stack);
				}
			}
		}
	}
}
