/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:43:54 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:44:28 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	countelem(t_linked *head)
{
	int	i;

	if (head == NULL)
		return (0);
	i = 1;
	while (head->next != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
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
