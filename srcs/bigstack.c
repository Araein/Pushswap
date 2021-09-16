#include "Pushswap.h"


void	bigstack4(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	int i;
	int choose;
	int test;

	test = 0;
	i = 0;
//	if(stack->size % 2 != 0)
//			test++;
	while (i <= stack->keep)
	{
		if ((*heada)->value <= stack->thirdquart)
		{
			givenode(heada, headb, 1, stack);
			i++;
//			stack->keep--;
		} else
	toptobottom(heada, 0, stack);
	printf("coucou4 i = %d / median= %d / value = %d", i, stack->median, (*heada)->value);
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
	printf("\nkeep4 = %d", stack->keep);
}

void	bigstack3(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	int i;
	int choose;
	int test;

	test = 0;
	i = 0;
//	if(stack->size % 2 != 0)
	//		test++;
	while (i < stack->size/4 + test)
	{
		if ((*heada)->value >= stack->thirdquart && (*heada)->value < stack->median)
		{
			givenode(heada, headb, 1, stack);
			i++;
			stack->keep--;
		} else
	toptobottom(heada, 0, stack);
	printf("coucou3 i = %d / median= %d / value = %d", i, stack->median, (*heada)->value);
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
	printf("\nkeep3 = %d", stack->keep);
}
void	bigstack2(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	int i;
	int choose;
	int test;

	test = 0;
	i = 0;
//	if(stack->size % 2 != 0)
//			test++;
	while (i < stack->size/4 + test)
	{
		if ((*heada)->value >= stack->median && (*heada)->value < stack->firstquart)
		{
			givenode(heada, headb, 1, stack);
			i++;
			stack->keep--;
		} else
	toptobottom(heada, 0, stack);
	printf("coucou2 i = %d / median= %d / value = %d", i, stack->median, (*heada)->value);
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
	printf("\nkeep2 = %d", stack->keep);
}

void	bigstack(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*tmp;
	int			i;
	int			choose;
	int			test;

	test = 0;
	i = 0;
	tmp = *heada;
	tmp = *headb;
	choose = 0;
	
	stack->keep = stack->size;
	
	while (i <= stack->size/4)
	{
		if ((*heada)->value >= stack->firstquart)
		{
			givenode(heada, headb, 1, stack);
			i++;
			stack->keep--;
		} else
		toptobottom(heada, 0, stack);
		printf("coucou");
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
	printf("\nkeep = %d\n", stack->keep);
	bigstack2(heada, headb, stack);
	bigstack3(heada, headb, stack);
	bigstack4(heada, headb, stack);
}
