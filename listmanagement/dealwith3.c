
#include "Pushswap.h"

void firsttinier (stack1_t **head)
{
	
		if ((*head)->next->value < (*head)->next->next->value)
			return ;
		if ((*head)->value > (*head)->next->next->value)
		{
			bottomtotop(head);
			return ;
		} else
		swapfirst(*head);
		toptobottom(head);
		return ;
}

void firstbigger (stack1_t **head)
{
		if ((*head)->next->value > (*head)->next->next->value)
		{
			swapfirst(*head);
			bottomtotop(head);
			return ;
		}
		if ((*head)->value < (*head)->next->next->value)
		{
			swapfirst(*head);
			return ;
		} else
		toptobottom(head);
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
