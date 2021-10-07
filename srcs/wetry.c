#include "Pushswap.h"

void	switchies( int value, stack1_t **head)
{
	stack1_t	*tmp;

	tmp = createnode(value);
	(*head)->next = tmp;
	tmp->prev = *head;
	*head = (*head)->next;
	(*head)->next = NULL;
}

stack1_t	*listit(t_stack *stack, int size)
{
	stack1_t	*ref;
	stack1_t	*head;
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

void	rrfunc(stack1_t	**heada, stack1_t **headb, t_stack *stack)
{
	toptobottom(heada, 2, stack);
	toptobottom(headb, 2, stack);
	ft_putstr("rr\n");
}

void	tril(stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **del)
{
	stack1_t	*tmp;
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

void	last(stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **del)
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

void	botopfunc(stack1_t *tmp, stack1_t **ha, t_stack *stack)
{
	tmp = tmp->prev;
	bottomtotop(ha, 0, stack);
}

void	gf(stack1_t **ha, stack1_t **hb, t_stack *stack)
{
	givenode(ha, hb, 1, stack);
	stack->keep++;
}

stack1_t	*reinit(stack1_t **ha, t_stack *stack)
{
	stack1_t	*tmp;

	stack->j = 0;
	tmp = *ha;
	return (tmp);
}

void	chungus( stack1_t **ha, stack1_t **hb, t_stack *stack, stack1_t **del)
{
	stack1_t	*tmp;
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

void	dealwithmore(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*delimiter;
	int			i;
	stack1_t	*tmp;
	stack1_t	*tmp2;

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
