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
	t_stack		stack;
	

	headb = NULL;
	heada = generatestack(argc, argv);
	stack.size = countelem(heada);



	printf("\n--------------- heada before :\n");
	printlist(heada);

	printf("\n//////////////\n");
	sortstack(&heada, &stack);
	findmedian(&stack);
	printf("\n la mediane est : %d\n", stack.median);
	
	if (stack.size == 3)
		triplechar(&heada);
	else if (stack.size < 6)
	   fivechar(&heada, &headb, stack.size);	
	else if (stack.size < 101)
		stacked(&heada, &headb, &stack);

	printf("\n--------------- heada after :\n");
	printlist(heada);

	printf("\n--------------- headb :\n");
	printlist(headb);

	return (0);
}
