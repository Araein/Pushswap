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

	printf("\nCOUCOU\n");
	return (num * signe);
}

int main (int argc, char **argv)
{
	stack1_t *head;
//	stack1_t *head2;
//	stack1_t *head3;



	head = generatestack(argc, argv);
	
//	head2 = generatestack(10);
//	head3 = generatestack(10);

//	bottomtotop(&head2);
//	toptobottom(&head3);
//	givenode(&head, &head2);
//	printf("\n%d -- %d\n", argc, ft_atoi(argv[1]));
	printf("\n--------------- head :\n");
	printlist(head);
//	printf("\n head a %d elem", countelem(head));
/*	printf("\n--------------- head2 bottomtotop :\n");
	printlist(head2);
	printf("\n--------------- head3 toptobottom :\n");
	printlist(head3);
*/

//	printf("\n head2 a %d elem", countelem(head2));


	return (0);
}
