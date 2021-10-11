/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:47 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 16:22:53 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

t_linked	*createnode(int value)
{
	t_linked	*result;

	result = malloc(sizeof(t_linked));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void	finalstep(t_linked **head, t_linked **tmp, t_stack *stack)
{
	if (stack->operation > 0)
		(*head)->prev = *tmp;
	*head = *tmp;
	stack->j--;
	stack->operation++;
}

t_linked	*generatestack(int argc, char **argv, t_stack *stack)
{
	t_linked	*head;
	t_linked	*tmp;
	char		**splited;

	stack->operation = 0;
	head = NULL;
	while (argc > 1)
	{
		splited = ft_split(argv[argc - 1], ' ');
		stack->j = tablen(splited);
		while (stack->j >= 1)
		{
			checkerror(splited, stack->j, stack);
			if (stack->error == 1)
				return (error(splited, head));
			tmp = createnode(ft_atoi(splited[stack->j - 1]));
			tmp->next = head;
			finalstep(&head, &tmp, stack);
		}
		freetab(splited);
		argc--;
	}
	return (head);
}

t_linked	*swapfirst(t_linked **head, int boo, t_stack *stack)
{
	t_linked	*tmp;
	t_linked	*tmp2;

	tmp = *head;
	tmp2 = (*head)->next;
	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->prev = NULL;
	tmp2->next = tmp;
	*head = tmp2;
	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head)->next;
	if (boo == 1)
		ft_putstr("sb\n");
	if (boo == 2)
		return (*head);
	else
		ft_putstr("sa\n");
	stack->operation += 1;
	return (*head);
}

void	givenode( t_linked **head, t_linked **head2, int boo, t_stack *stack)
{
	t_linked	*tmp;

	if (countelem (*head) == 0)
		return ;
	tmp = *head;
	if (countelem (*head) > 1)
		(*head)->next->prev = NULL;
	*head = (*head)->next;
	if (*head2 == NULL)
	{
		*head2 = tmp;
		(*head2)->next = NULL;
		(*head2)->prev = NULL;
	}
	else
	{	
		tmp->next = *head2;
		(*head2)->prev = tmp;
		*head2 = tmp;
	}
	if (boo == 1)
		ft_putstr("pb\n");
	else
		ft_putstr("pa\n");
	stack->operation += 1;
}
