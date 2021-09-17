
#include "Pushswap.h"

void firsttinier (stack1_t **head, t_stack *stack)
{
	
		if ((*head)->next->value < (*head)->next->next->value)
			return ;
		if ((*head)->value > (*head)->next->next->value)
		{
			bottomtotop(head, 0, stack);
			return ;
		} else
		swapfirst(head, 0, stack);
		toptobottom(head, 0, stack);
		return ;
}

void firstbigger (stack1_t **head, t_stack *stack)
{
		if ((*head)->next->value > (*head)->next->next->value)
		{
			//		printlist(*head);
		swapfirst(head, 0, stack);
			//	printlist(*head);
			bottomtotop(head, 0, stack);
//			printlist(*head);
			return ;
		}
		if ((*head)->value < (*head)->next->next->value)
		{
			swapfirst(head, 0, stack);
			return ;
		} else
		toptobottom(head, 0, stack);
		return ;
}

void triplechar(stack1_t **head, t_stack *stack)
{
	if ((*head)->value < (*head)->next->value)
	{
		firsttinier (head,stack);
		return ;
	}	
	
	if ((*head)->value > (*head)->next->value)
	{
		firstbigger (head, stack);
		return ;
	}
}
