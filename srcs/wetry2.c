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
