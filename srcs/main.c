/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:27 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:41:30 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	init(t_linked **heada, t_linked **headb, t_stack *stack)
{
	stack->value = 0;
	stack->size = 0;
	stack->therest = 0;
	stack->sorted = NULL;
	*headb = NULL;
	*heada = NULL;
	stack->operation = 0;
	stack->one = 11;
	stack->j = 0;
}

void	checkdoublon(t_linked **head, t_stack *stack)
{
	int			i;
	t_linked	*tmp;
	t_linked	*tmp2;
	int			d;

	d = 0;
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
			stack->error = 1;
		tmp = tmp->next;
	}
	return ;
}

void	checkorder(t_linked **head, t_stack *stack)
{
	int			i;
	int			d;
	t_linked	*tmp;
	t_linked	*tmp2;

	d = 0;
	i = 0;
	tmp = *head;
	tmp2 = *head;
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
		*head = tmp2;
	}
	return ;
}

int	littlenum(t_linked **heada, t_linked **sorted, t_stack *stack)
{
	if (stack->size <= 1)
	{
		freelist(heada);
		freelist(sorted);
		return (0);
	}
	if (stack->size == 2)
	{
		if ((*heada)->value > (*heada)->next->value)
			swapfirst(heada, 0, stack);
		freelist(heada);
		freelist(sorted);
		return (0);
	}
	return (0);
}

int	launchit(t_linked **ha, t_linked **hb, t_linked **sorted, t_stack *stack)
{
	int	size;

	size = 0;
	if (stack->size == 5)
		size = 1;
	if (stack->size == 3)
		triplechar(ha, stack);
	else if (stack->size < 6)
		fivechar(ha, hb, size, stack);
	else
	{		
		sortstack(sorted, stack);
		if (stack->size < 201)
			stack->one = 5;
		dealwithmore(ha, hb, stack);
	}
	freelist(sorted);
	freelist(ha);
	return (0);
}

int	main(int argc, char **argv)
{
	t_linked	*heada;
	t_linked	*headb;
	t_linked	*sorted;
	t_stack		stack;

	if (argc < 2 || argv[1] == 0)
		return (0);
	init(&heada, &headb, &stack);
	stack.error = 0;
	heada = generatestack(argc, argv, &stack);
	stack.size = countelem(heada);
	checkorder(&heada, &stack);
	checkdoublon(&heada, &stack);
	if (stack.error > 0)
	{
		if (stack.error == 1)
			ft_putstr("Error\n");
		if (heada)
			freelist(&heada);
		return (0);
	}
	sorted = generatestack(argc, argv, &stack);
	if (stack.size <= 2)
		return (littlenum(&heada, &sorted, &stack));
	else
		return (launchit(&heada, &headb, &sorted, &stack));
	return (0);
}
