#include "Pushswap.h"


int		justincase(stack1_t **head, stack1_t *tmp, t_stack *stack)
{

	if ((*head)->value > tmp->prev->value && tmp->value < tmp->prev->value &&
	(*head)->value < (*head)->next->value && (*head)->next->value < (*head)->next->next->value)	
	{
		bottomtotop(head, 0, stack);
		bottomtotop(head, 0, stack);
		swapfirst(head, 0, stack);	
		return (1);
	}
	return (0);
}
void	fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stack)
{
	stack1_t *tmp2;
	int i;
	stack1_t *tmp;

	i = 0;

//		givenode(head, head2, 1, stack);
		if (stack->size == 5)
		{
			tmp = (*head)->next->next->next->next;	
			i  = justincase(head, tmp, stack);
			if ( i == 1)
				return ;
			givenode(head, head2, 1, stack);
		}
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
			else if ((*head)->value > (*head)->next->next->next->value)
			{
				bottomtotop(head, 0, stack);
				swapfirst(head, 0, stack);
				toptobottom(head, 0, stack);
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
				}/*
				if (tmp2->next != NULL && tmp2->value > tmp2->next->value)
				{
					toptobottom(head, 0, stack);
					toptobottom(head, 0, stack);
					swapfirst(head, 0, stack);
					bottomtotop(head, 0, stack);
					bottomtotop(head, 0, stack);
				}*/
			}
		}
	}
}
