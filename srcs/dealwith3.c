
#include "Pushswap.h"

void firsttinier (stack1_t **head)
{
	
		if ((*head)->next->value < (*head)->next->next->value)
			return ;
		if ((*head)->value > (*head)->next->next->value)
		{
			bottomtotop(head, 0);
			return ;
		} else
		swapfirst(*head, 0);
		toptobottom(head, 0);
		return ;
}

void firstbigger (stack1_t **head)
{
		if ((*head)->next->value > (*head)->next->next->value)
		{
			swapfirst(*head, 0);
			bottomtotop(head, 0);
			return ;
		}
		if ((*head)->value < (*head)->next->next->value)
		{
			swapfirst(*head, 0);
			return ;
		} else
		toptobottom(head, 0);
		return ;
}

void triplechar(stack1_t **head)
{
	if ((*head)->value < (*head)->next->value)
	{
		firsttinier (head);
		return ;
	}	
	
	if ((*head)->value > (*head)->next->value)
	{
		firstbigger (head);
		return ;
	}
}
