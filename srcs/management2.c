/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:43:54 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 16:23:25 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	checkdoublon(t_linked **head, t_stack *stack)
{
	int			i;
	t_linked	*tmp;
	t_linked	*tmp2;
	int			d;

	tmp = *head;
	while (tmp != NULL && stack->error != 1)
	{	
		i = tmp->value;
		tmp2 = *head;
		d = 0;
		while (tmp2 != NULL)
		{
			if (tmp2->value == i)
				d++;
			tmp2 = tmp2->next;
		}
		if (d > 1)
		{
			ft_putstr("Error\n");
			stack->error = 1;
		}
		tmp = tmp->next;
	}
	return ;
}

void	checkorder(t_linked **head, t_stack *stack)
{
	int			i;
	int			d;
	t_linked	*tmp;

	d = 0;
	i = 0;
	tmp = *head;
	if (stack->size == 0)
		stack->error = 1;
	else
	{
		while (tmp->next != NULL && stack->error != 2)
		{	
			i++;
			if (tmp->value < tmp->next->value)
				d++;
			tmp = tmp->next;
		}
		if (i == d)
			stack->error = 2;
		else
			checkdoublon(head, stack);
	}
	return ;
}

void	toptobottom(t_linked **head, int boo, t_stack *stack)
{
	t_linked	*tmp;
	t_linked	*tmp2;

	tmp = *head;
	tmp2 = (*head)->next;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	while ((*head)->next != NULL)
		*head = (*head)->next;
	tmp->prev = *head;
	tmp->next = NULL;
	(*head)->next = tmp;
	*head = tmp2;
	if (boo == 1)
		ft_putstr("rb\n");
	if (boo == 2)
		return ;
	if (boo == 0)
		ft_putstr("ra\n");
	stack->operation += 1;
}

void	bottomtotop(t_linked **head, int boo, t_stack *stack)
{
	t_linked	*tmp;
	t_linked	*tmp2;

	while ((*head)->next != NULL)
		*head = (*head)->next;
	tmp2 = *head;
	tmp = (*head)->prev;
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	tmp->next = NULL;
	tmp2->prev = NULL;
	(*head)->prev = tmp2;
	tmp2->next = *head;
	*head = tmp2;
	if (boo == 1)
		ft_putstr("rrb\n");
	if (boo == 2)
		return ;
	if (boo == 0)
		ft_putstr("rra\n");
	stack->operation += 1;
}
