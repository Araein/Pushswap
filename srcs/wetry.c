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
