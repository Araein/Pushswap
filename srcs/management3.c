#include "Pushswap.h"

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