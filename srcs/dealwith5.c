#include "Pushswap.h"

int	justincase(stack1_t **head, stack1_t *tmp, t_stack *stack)
{
	if ((*head)->value > tmp->prev->value
		&& tmp->value < tmp->prev->value
		&& (*head)->value < (*head)->next->value
		&& (*head)->next->value < (*head)->next->next->value)
	{
		bottomtotop(head, 0, stack);
		bottomtotop(head, 0, stack);
		swapfirst(head, 0, stack);
		return (1);
	}
	return (0);
}

int	doesitfit(stack1_t **heada, stack1_t **headb, int d, t_stack *stack)
{
	stack1_t	*tmp;
	stack1_t	*tmp2;
	int			min;
	int			max;

	tmp = *heada;
	tmp2 = *heada;
	while (tmp2 != NULL)
	{
		if (tmp2->value < tmp->value)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	min = tmp->value;
	tmp = *heada;
	tmp2 = *heada;
	while (tmp2 != NULL)
	{
		if (tmp2->value > tmp->value)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	max = tmp->value;
	tmp2 = *heada;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp = *heada;
	if ((*headb)->value > tmp->value && (*headb)->value < tmp->next->value)
	{
		toptobottom(heada, 0, stack);
		return (1);
	}
	else if ((*headb)->value < tmp2->value
		&& (*headb)->value > tmp2->prev->value)
	{
		bottomtotop(heada, 0, stack);
		return (1);
	}
	else if (d == 1)
	{
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		if ((*headb)->value > tmp->value && (*headb)->value < tmp2->value)
		{
			toptobottom(heada, 0, stack);
			toptobottom(heada, 0, stack);
			return (1);
		}
	}
	tmp2 = *heada;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp = *heada;
	if ((*heada)->value == max && tmp2->value == min)
		return (1);
	if (tmp2->value == max && (*heada)->value == min)
		return (1);
	return (0);
}

void	fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stack)
{
	stack1_t	*tmp2;
	stack1_t	*tmp;
	int			i;
	int			d;
	int			j;

	d = 0;
	i = 1;
	size++;
	if (countelem(*head) == 5)
	{
		i++;
		d = 1;
	}
	while (countelem(*head) > 3)
		givenode(head, head2, 1, stack);
	triplechar(head, stack);
	while (i > 0)
	{		
		j = 0;
		tmp = *head;
		tmp2 = *head;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		if ((*head2)->value > tmp->value && (*head2)->value < tmp->next->value)
		{
			toptobottom(head, 0, stack);
			givenode(head2, head, 0, stack);
		}
		else if ((*head2)->value < tmp2->value
			&& (*head2)->value > tmp2->prev->value)
		{
			bottomtotop(head, 0, stack);
			givenode(head2, head, 0, stack);
		}
		else if (d == 1)
		{
			tmp = tmp->next;
			tmp2 = tmp2->prev;
			if ((*head2)->value > tmp->value && (*head2)->value < tmp2->value)
			{
				toptobottom(head, 0, stack);
				toptobottom(head, 0, stack);
				givenode(head2, head, 0, stack);
			}
			else
			{
				while (j == 0)
				{
					if (doesitfit(head, head2, d, stack) == 1)
						j = 1;
					if (j == 0)
						toptobottom(head, 0, stack);
				}
				givenode(head2, head, 0, stack);
			}
		}
		else
		{
			while (j == 0)
			{
				if (doesitfit(head, head2, d, stack) == 1)
					j = 1;
				if (j == 0)
					toptobottom(head, 0, stack);
			}
			givenode(head2, head, 0, stack);
		}
		i--;
	}
	i = 0;
	tmp = *head;
	tmp2 = *head;
	while (tmp2 != NULL)
	{
		if (tmp2->value < tmp->value)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	tmp2 = *head;
	while (tmp2->value != tmp->value)
	{
		tmp2 = tmp2->next;
		i++;
	}
	if (i > 3)
	{
		i = 5 - i;
		while (i > 0)
		{
			bottomtotop(head, 0, stack);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			toptobottom(head, 0, stack);
			i--;
		}
	}
}
