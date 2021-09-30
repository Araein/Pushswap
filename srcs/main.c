#include "Pushswap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

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


int		ft_atoi(const char *str)
{
	int signe;
	int i;
	int num;

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

int main (int argc, char **argv)
{
	stack1_t	*heada;
	stack1_t	*headb;
	stack1_t	*sorted;
	t_stack		stack;

	/*checker si cest aue des int, si ya pa de double si cest pas vide si ya pas de charac non desires*/
	/*segfault sur 2 chara*/
	/*boucle infinie sur 5 2 4 8 6 4 -9 1*/
						/*4 65 7 21 3*/
						/*5 4 2 6 3*/
						/*2 3 1 4 0*/
	/*checksi tout est un integer*/
	/*LEAKS*/

	//check si liste est deja classee

	headb = NULL;
	if (argv[1] == NULL)
		return (0);

	/*
	 * char **args;
	 * args = doargs (argc, argv);
	*/

	heada = generatestack(argc, argv);
	sorted = generatestack(argc, argv);
	stack.size = countelem(heada);

	if (stack.size < 1)
		return (0);
	if (stack.size == 2)
	{
		if ((*heada).value > (*heada).next->value)
			swapfirst(&heada, 0, &stack);
		return (0);
	}
	stack.operation = 0;
	
//	GERER DOUBLONS ///// NOMBRE UNIQUE ///// DUO DE NOMBRE // charac non demandes // REGLER PUTAIN DE FIRSTSWAP

	stack.one = 11;
	if (stack.size == 3)
		triplechar(&heada, &stack);
	else if (stack.size < 6)
		fivechar(&heada, &headb, stack.size, &stack);	
	else
	{		
		sortstack(&sorted, &stack);
		if (stack.size < 201)
			stack.one = 5;
		dealwithmore(&heada, &headb, &stack);	
	}
/*	printf("\n");
	printlist(heada);
	printf("\n b === \n");
	printlist(headb);
*/
	freelist(stack.sorted);
	freelist(heada);
	return (0);
}
