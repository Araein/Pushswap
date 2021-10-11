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

void	dominmax(stack1_t **ha, stack1_t *tmp, stack1_t *tmp2, t_stack *stack)
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

int	doublettob(stack1_t **heada, t_stack *stack)
{
	toptobottom(heada, 0, stack);
	toptobottom(heada, 0, stack);
	return (1);
}

int	btotorttob(stack1_t **heada, t_stack *stack, int i)
{
	if (i == 1)
		toptobottom(heada, 0, stack);
	else
		bottomtotop(heada, 0, stack);
	return (1);
}

int	output(stack1_t **heada, stack1_t *tmp2, t_stack *stack)
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

int	doesitfit(stack1_t **heada, stack1_t **headb, int d, t_stack *stack)
{
	stack1_t	*tmp;
	stack1_t	*tmp2;

	tmp = *heada;
	tmp2 = *heada;
	dominmax(heada, tmp, tmp2, stack);
	tmp2 = *heada;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp = *heada;
	if ((*headb)->value > tmp->value && (*headb)->value < tmp->next->value)
		return (btotorttob(heada, stack, 1));
	else if ((*headb)->value < tmp2->value
		&& (*headb)->value > tmp2->prev->value)
		return (btotorttob(heada, stack, 2));
	else if (d == 1)
	{
		tmp = tmp->next;
		tmp2 = tmp2->prev;
		if ((*headb)->value > tmp->value && (*headb)->value < tmp2->value)
			return (doublettob(heada, stack));
	}
	return (output(heada, tmp2, stack));
}

void	movetmp(stack1_t **tmp, stack1_t **tmp2, stack1_t **head)
{
	while (*tmp2 != NULL)
	{
		if ((*tmp2)->value < (*tmp)->value)
			*tmp = *tmp2;
		*tmp2 = (*tmp2)->next;
	}
	*tmp2 = *head;
}

void	finishthejob(stack1_t **head, t_stack *stack)
{
	int			i;
	stack1_t	*tmp;
	stack1_t	*tmp2;

	i = 0;
	tmp = *head;
	tmp2 = *head;
	movetmp(&tmp, &tmp2, head);
	while (tmp2->value != tmp->value)
	{
		tmp2 = tmp2->next;
		i++;
	}
	if (i > 3)
	{
		i = 5 - i + 1;
		while (--i > 0)
			bottomtotop(head, 0, stack);
	}
	else
	{
		i++;
		while (--i > 0)
			toptobottom(head, 0, stack);
	}
}

void	doj(stack1_t **head, stack1_t **head2, t_stack *stack, int d)
{
	int	j;

	j = 0;
	while (j == 0)
	{
		if (doesitfit(head, head2, d, stack) == 1)
			j = 1;
		if (j == 0)
			toptobottom(head, 0, stack);
	}
	givenode(head2, head, 0, stack);
}

void	toptop(stack1_t **head, stack1_t **head2, t_stack *stack)
{
	toptobottom(head, 0, stack);
	toptobottom(head, 0, stack);
	givenode(head2, head, 0, stack);
}

void	botortop(stack1_t **head, stack1_t **head2, t_stack *stack, int i)
{
	if (i == 1)
	{
		toptobottom(head, 0, stack);
		givenode(head2, head, 0, stack);
	}
	if (i == 2)
	{
		bottomtotop(head, 0, stack);
		givenode(head2, head, 0, stack);
	}
}

void	relou(stack1_t *tmp, stack1_t *tmp2)
{
	tmp = tmp->next;
	tmp2 = tmp2->prev;
}

int	pretri(stack1_t **head, stack1_t **head2, t_stack *stack)
{
	int	i;

	if (countelem(*head) == 5)
		i = 3;
	else
		i = 2;
	while (countelem(*head) > 3)
		givenode(head, head2, 1, stack);
	triplechar(head, stack);
	return (i);
}

void	resetline(stack1_t **tmp2)
{
	while ((*tmp2)->next != NULL)
		*tmp2 = (*tmp2)->next;
}

void	fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stack)
{
	stack1_t	*tmp2;
	stack1_t	*tmp;
	int			i;

	i = pretri(head, head2, stack);
	while (--i > 0)
	{		
		tmp = *head;
		tmp2 = *head;
		resetline(&tmp2);
		if ((*head2)->value > tmp->value && (*head2)->value < tmp->next->value)
			botortop(head, head2, stack, 1);
		else if ((*head2)->value < tmp2->value
			&& (*head2)->value > tmp2->prev->value)
			botortop(head, head2, stack, 2);
		else if (countelem (*head) == 5)
			if ((*head2)->value > tmp->next->value
				&& (*head2)->value < tmp2->prev->value)
				toptop(head, head2, stack);
		else
			doj(head, head2, stack, size);
		else
			doj(head, head2, stack, size);
	}
	finishthejob(head, stack);
}
