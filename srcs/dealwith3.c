/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealwith3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:39:44 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:40:13 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	firsttinier(t_linked **head, t_stack *stack)
{
	if ((*head)->next->value < (*head)->next->next->value)
		return ;
	if ((*head)->value > (*head)->next->next->value)
	{
		bottomtotop(head, 0, stack);
		return ;
	}
	else
		swapfirst(head, 0, stack);
	toptobottom(head, 0, stack);
	return ;
}

void	firstbigger(t_linked **head, t_stack *stack)
{
	if ((*head)->next->value > (*head)->next->next->value)
	{
		swapfirst(head, 0, stack);
		bottomtotop(head, 0, stack);
		return ;
	}
	if ((*head)->value < (*head)->next->next->value)
	{
		swapfirst(head, 0, stack);
		return ;
	}
	else
		toptobottom(head, 0, stack);
	return ;
}

void	triplechar(t_linked **head, t_stack *stack)
{
	if ((*head)->value < (*head)->next->value)
	{
		firsttinier(head, stack);
		return ;
	}		
	if ((*head)->value > (*head)->next->value)
	{
		firstbigger(head, stack);
		return ;
	}
}
