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

	/*checker si cest aue des int, si ya pa de double si cest pas vide si ya pas de charac non desires*/
	/*segfault sur 2 chara*/
	/*boucle infinie sur 5 2 4 8 6 4 -9 1*/
						/*4 65 7 21 3*/
						/*5 4 2 6 3*/
						/*2 3 1 4 0*/
	/*checksi tout est un integer*/
	/*LEAKS*/

	//check si liste est deja classee
	//virer les printf

	headb = NULL;
	if (argv[1] == NULL)
		return (0);
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

/*	printf("\n--------------- heada before :\n");
	printlist(heada);
*/
//	printf("\n//////////////\n");
//	sortstack(&sorted, &stack);
//	findmedian(&stack);
//	printf("\n la size est : %d\n", stack.size);
//	GERER DOUBLONS ///// NOMBRE UNIQUE ///// DUO DE NOMBRE // charac non demandes // REGLER PUTAIN DE FIRSTSWAP
	if (stack.size == 3)
		triplechar(&heada, &stack);
	else if (stack.size < 6)
	   fivechar(&heada, &headb, stack.size, &stack);	
	else
	{		
		sortstack(&sorted, &stack);
		findmedian(&stack);
		if (stack.size < 101)
			bigstack(&heada, &headb, &stack);
		else
			bigstack(&heada, &headb, &stack);
	}


/*
	printf("\n--------------- heada after :\n");
	printlist(heada);

	printf("\n--------------- headb :\n");
	printlist(headb);
	printf("\nNOMBRE DE COMMANDES -> %d\n", stack.operation);
	printf("\n\nfirst = %d // median = %d // third = %d\n // operation = %d", stack.firstquart, stack.median, stack.thirdquart, stack.operation);
*/
	freelist(heada);
	return (0);
}
