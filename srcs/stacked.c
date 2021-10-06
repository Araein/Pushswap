/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacked.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 04:11:42 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/06 04:55:22 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	swapthem(stack1_t **tmp, int d)
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
}

int	sortstack( stack1_t **head, t_stack *stack)
{
	stack1_t	*tmp;
	stack1_t	*keep;

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
	stack1_t	*tmp;
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

void	findhigherlower( stack1_t **head, t_stack *stack)
{
	stack1_t	*higher;
	stack1_t	*lower;
	stack1_t	*tmp;

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

int	decidewhofirst( stack1_t **head, t_stack *stack, int i)
{
	stack1_t	*tmp;
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

void	flipit( stack1_t **headb, stack1_t **heada, t_stack *stack, int choose)
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
