/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:47 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:43:47 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

void	freelist(t_linked **head)
{
	t_linked	*tmp;

	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

t_linked	*createnode(int value)
{
	t_linked	*result;

	result = malloc(sizeof(t_linked));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_isdigit(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_linked	*error(char **splited, t_linked *head)
{
	freetab(splited);
	return (head);
}

void	checkerror(char **splited, int j, t_stack *stack)
{
	if (!(ft_isdigit(splited[j - 1])))
		stack->error = 1;
	if (stack->error == 1)
		return ;
	if (stack->error == 0 && (ft_atoi(splited[j - 1]) > 2147483647
			|| ft_atoi(splited[j - 1]) < -2147483648))
		stack->error = 1;
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
