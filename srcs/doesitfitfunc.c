#include "Pushswap.h"

int	justincase(t_linked **head, t_linked *tmp, t_stack *stack)
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

void	dominmax(t_linked **ha, t_linked *tmp, t_linked *tmp2, t_stack *stack)
{
	while (tmp2 != NULL)
	{
		if (tmp2->value < tmp->value)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	stack->min = tmp->value;
	tmp = *ha;
	tmp2 = *ha;
	while (tmp2 != NULL)
	{
		if (tmp2->value > tmp->value)
			tmp = tmp2;
		tmp2 = tmp2->next;
	}
	stack->max = tmp->value;
	tmp2 = *ha;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp = *ha;
}

int	doublettob(t_linked **heada, t_stack *stack)
{
	toptobottom(heada, 0, stack);
	toptobottom(heada, 0, stack);
	return (1);
}

int	btotorttob(t_linked **heada, t_stack *stack, int i)
{
	if (i == 1)
		toptobottom(heada, 0, stack);
	else
		bottomtotop(heada, 0, stack);
	return (1);
}

int	output(t_linked **heada, t_linked *tmp2, t_stack *stack)
{
	tmp2 = *heada;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	if ((*heada)->value == stack->max && tmp2->value == stack->min)
		return (1);
	if (tmp2->value == stack->max && (*heada)->value == stack->min)
		return (1);
	return (0);
}
