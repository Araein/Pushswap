/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wetry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:41:38 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:42:10 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	switchies( int value, t_linked **head)
{
	t_linked	*tmp;

	tmp = createnode(value);
	(*head)->next = tmp;
	tmp->prev = *head;
	*head = (*head)->next;
	(*head)->next = NULL;
}

t_linked	*listit(t_stack *stack, int size)
{
	t_linked	*ref;
	t_linked	*head;
	int			i;
	int			j;

	stack->value = stack->size / size;
	stack->therest = stack->size % size;
	i = -1;
	ref = stack->sorted;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < stack->value)
			ref = ref->next;
		if (i == 0)
			head = createnode(ref->value);
		else
			switchies (ref->value, &head);
	}
	head->next = NULL;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}

void	rrfunc(t_linked	**heada, t_linked **headb, t_stack *stack)
{
	toptobottom(heada, 2, stack);
	toptobottom(headb, 2, stack);
	ft_putstr("rr\n");
}

void	tril(t_linked **heada, t_linked **headb, t_stack *stack, t_linked **del)
{
	t_linked	*tmp;
	int			i;

	i = -1;
	tmp = *heada;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (++i < stack->size - stack->keep)
	{
		if ((*heada)->value <= (*del)->value)
			givenode(heada, headb, 1, stack);
		else if (i > 1 && (*headb)->value < (*headb)->next->value)
			rrfunc(heada, headb, stack);
		else if ((stack->j == 0 || i == 0) && tmp->value <= (*del)->value)
		{
			tmp = tmp->prev;
			bottomtotop(heada, 0, stack);
		}
		else
			toptobottom(heada, 0, stack);
		stack->j++;
	}
}

void	last(t_linked **heada, t_linked **headb, t_stack *stack, t_linked **del)
{
	int			i;
	int			choose;

	stack->j = 0;
	tril(heada, headb, stack, del);
	i = countelem(*headb);
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
}

void	botopfunc(t_linked *tmp, t_linked **ha, t_stack *stack)
{
	tmp = tmp->prev;
	bottomtotop(ha, 0, stack);
}

void	gf(t_linked **ha, t_linked **hb, t_stack *stack)
{
	givenode(ha, hb, 1, stack);
	stack->keep++;
}

t_linked	*reinit(t_linked **ha, t_stack *stack)
{
	t_linked	*tmp;

	stack->j = 0;
	tmp = *ha;
	return (tmp);
}

void	chungus( t_linked **ha, t_linked **hb, t_stack *stack, t_linked **del)
{
	t_linked	*tmp;
	int			i;

	tmp = reinit (ha, stack);
	i = 0;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (i < stack->size / stack->one)
	{
		if ((*ha)->value > (*del)->value
			&& ((*del)->prev == NULL || (*ha)->value <= (*del)->prev->value))
		{
			gf(ha, hb, stack);
			i++;
		}
		else if (i > 1 && (*hb)->value < (*hb)->next->value)
			rrfunc(ha, hb, stack);
		else if ((stack->j == 0 || i == 0) && (tmp)->value > (*del)->value
			&& ((*del)->prev == NULL || (tmp)->value <= (*del)->prev->value))
			botopfunc(tmp, ha, stack);
		else
			toptobottom(ha, 0, stack);
		stack->j++;
	}
	*del = (*del)->next;
}

void	dealwithmore(t_linked **heada, t_linked **headb, t_stack *stack)
{
	t_linked	*delimiter;
	int			i;
	t_linked	*tmp;
	t_linked	*tmp2;

	i = 0;
	delimiter = listit(stack, stack->one);
	tmp = delimiter;
	tmp2 = delimiter;
	while (tmp->next != NULL)
		tmp = tmp->next;
	stack->keep = 0;
	delimiter->prev = NULL;
	while (i < stack->one - 1)
	{
		chungus(heada, headb, stack, &delimiter);
		i++;
	}
	last(heada, headb, stack, &tmp);
	freelist(&tmp2);
}
