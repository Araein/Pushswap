#include "Pushswap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

long long	ft_atoi(const char *str)
{
	long long	signe;
	long long	i;
	long long	num;

	i = 0;
	signe = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * signe);
}

void	checkdoublon(stack1_t **head, t_stack *stack)
{
	int			i;
	stack1_t	*tmp;
	stack1_t	*tmp2;
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

int	littlenum(stack1_t **heada, stack1_t **sorted, t_stack *stack)
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

void	init(stack1_t **heada, stack1_t **headb, t_stack *stack)
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

int	launchit(stack1_t **ha, stack1_t **hb, stack1_t **sorted, t_stack *stack)
{
	if (stack->size == 3)
		triplechar(ha, stack);
	else if (stack->size < 6)
		fivechar(ha, hb, stack->size, stack);
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
	stack1_t	*heada;
	stack1_t	*headb;
	stack1_t	*sorted;
	t_stack		stack;

	init(&heada, &headb, &stack);
	if (argv[1] == NULL)
		return (0);
	stack.error = 0;
	heada = generatestack(argc, argv, &stack);
	checkdoublon(&heada, &stack);
	if (stack.error == 1)
	{
		ft_putstr("Error");
		if (heada)
			freelist(&heada);
		return (0);
	}
	sorted = generatestack(argc, argv, &stack);
	stack.size = countelem(heada);
	if (stack.size <= 2)
		return (littlenum(&heada, &sorted, &stack));
	else
		return (launchit(&heada, &headb, &sorted, &stack));
	return (0);
}
