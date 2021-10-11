/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealwith5func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:21:54 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 16:22:02 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	movetmp(t_linked **tmp, t_linked **tmp2, t_linked **head)
{
	while (*tmp2 != NULL)
	{
		if ((*tmp2)->value < (*tmp)->value)
			*tmp = *tmp2;
		*tmp2 = (*tmp2)->next;
	}
	*tmp2 = *head;
}

void	finishthejob(t_linked **head, t_stack *stack)
{
	int			i;
	t_linked	*tmp;
	t_linked	*tmp2;

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

void	doj(t_linked **head, t_linked **head2, t_stack *stack, int d)
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

void	toptop(t_linked **head, t_linked **head2, t_stack *stack)
{
	toptobottom(head, 0, stack);
	toptobottom(head, 0, stack);
	givenode(head2, head, 0, stack);
}

void	botortop(t_linked **head, t_linked **head2, t_stack *stack, int i)
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
