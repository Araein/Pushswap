/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealwith5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:38:53 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 16:21:40 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	doesitfit(t_linked **heada, t_linked **headb, int d, t_stack *stack)
{
	t_linked	*tmp;
	t_linked	*tmp2;

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

void	relou(t_linked *tmp, t_linked *tmp2)
{
	tmp = tmp->next;
	tmp2 = tmp2->prev;
}

int	pretri(t_linked **head, t_linked **head2, t_stack *stack)
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

void	resetline(t_linked **tmp2)
{
	while ((*tmp2)->next != NULL)
		*tmp2 = (*tmp2)->next;
}

void	fivechar(t_linked **head, t_linked **head2, int size, t_stack *stack)
{
	t_linked	*tmp2;
	t_linked	*tmp;
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
