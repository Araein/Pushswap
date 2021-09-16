#include "Pushswap.h"


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

	/*checker si cest aue des int, si ya pa de double si cest pas vide */
	/*segfault sur 2 chara*/
	/*boucle infinie sur 5 2 4 8 6 4 -9 1*/
						/*4 65 7 21 3*/
	headb = NULL;
	heada = generatestack(argc, argv);
	sorted = generatestack(argc, argv);
	stack.size = countelem(heada);


	stack.operation = 0;

//	printf("\n--------------- heada before :\n");
//	printlist(heada);

//	printf("\n//////////////\n");
	sortstack(&sorted, &stack);
	findmedian(&stack);
//	printf("\n la mediane est : %d\n", stack.median);
	
	if (stack.size == 3)
		triplechar(&heada, &stack);
	else if (stack.size < 6)
	   fivechar(&heada, &headb, stack.size, &stack);	
	else if (stack.size < 101)
		stacked(&heada, &headb, &stack);
	else
		bigstack(&heada, &headb, &stack);

	printf("\n--------------- heada after :\n");
	printlist(heada);

	printf("\n--------------- headb :\n");
	printlist(headb);
	printf("\nNOMBRE DE COMMANDES -> %d\n", stack.operation);
	printf("\n\nfirst = %d // median = %d // third = %d\n // operation = %d", stack.firstquart, stack.median, stack.thirdquart, stack.operation);
	freelist(heada);
	return (0);
}
