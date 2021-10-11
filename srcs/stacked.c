/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacked.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:44:48 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:45:58 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"
/*
void	swapthem(t_linked **tmp, int d)
{
	int	i;

	if (d == 1 && (*tmp)->value > (*tmp)->next->value)
	{
		i = (*tmp)->value;
		(*tmp)->value = (*tmp)->next->value;
		(*tmp)->next->value = i;
	}
	if (d == 2 && (*tmp)->value > (*tmp)->prev->value)
	{
		i = (*tmp)->value;
		(*tmp)->value = (*tmp)->prev->value;
		(*tmp)->prev->value = i;
	}
}*/

int	sortstack( t_linked **head, t_stack *stack)
{
	t_linked	*tmp;
	t_linked	*keep;

	keep = *head;
	while (*head != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			swapthem(&tmp, 1);
			tmp = tmp->next;
		}
		while (tmp->prev != NULL)
		{	
			swapthem(&tmp, 2);
			tmp = tmp->prev;
		}
		*head = (*head)->next;
	}
	*head = keep;
	stack->sorted = *head;
	return (1);
}

void	findmedian( t_stack *stack)
{
	t_linked	*tmp;
	int			i;

	i = -1;
	tmp = stack->sorted;
	while (i++ < stack->size / 2)
		tmp = tmp->next;
	stack->median = tmp->value;
	i = 0;
	tmp = stack->sorted;
	while (i < stack->size / 4)
	{
		tmp = tmp->next;
		i++;
	}
	stack->firstquart = tmp->value;
	i = 0;
	tmp = stack->sorted;
	while (i < stack->size - stack->size / 4)
	{
		tmp = tmp->next;
		i++;
	}
	stack->thirdquart = tmp->value;
}

void	findhigherlower( t_linked **head, t_stack *stack)
{
	t_linked	*higher;
	t_linked	*lower;
	t_linked	*tmp;

	tmp = *head;
	higher = *head;
	lower = *head;
	while (*head != NULL)
	{
		if ((*head)->value > lower->value)
			lower = *head;
		*head = (*head)->next;
	}
	stack->lower = lower;
	stack->higher = higher;
	*head = tmp;
}

int	decidewhofirst( t_linked **head, t_stack *stack, int i)
{
	t_linked	*tmp;
	int			middle;
	int			j;
	int			ret;

	middle = i / 2;
	j = 0;
	tmp = *head;
	stack->direction = 1;
	while (stack->lower->value != (*head)->value)
	{
		j++;
		*head = (*head)->next;
	}
	*head = tmp;
	if (j > middle)
	{
		j = i - j;
		stack->direction = 2;
	}
	ret = j;
	return (ret);
}

void	flipit( t_linked **headb, t_linked **heada, t_stack *stack, int choose)
{
	int	i;

	i = 0;
	if (stack->direction == 1)
	{
		while (i < choose)
		{
			i++;
			toptobottom (headb, 1, stack);
		}	
	}
	if (stack->direction == 2)
	{
		while (i < choose)
		{
			i++;
			bottomtotop (headb, 1, stack);
		}
	}
	givenode (headb, heada, 0, stack);
}
