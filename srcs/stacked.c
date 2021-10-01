#include "Pushswap.h"



int	sortstack( stack1_t **head, t_stack *stack)
{
	int			i;
	stack1_t	*tmp;
	stack1_t	*keep;

	keep = *head;
	while (*head != NULL)
	{
		tmp = *head;
        while (tmp->next != NULL)
        {
           if (tmp->value > tmp->next->value)
            {
              i = tmp->value;
              tmp->value = tmp->next->value;
              tmp->next->value = i;
            }
         tmp = tmp->next;
        } 
        while (tmp->prev != NULL)
        {
           if (tmp->value > tmp->prev->value) 
            {
              i = tmp->value;
              tmp->value = tmp->prev->value;
              tmp->prev->value = i;
            }
         tmp = tmp->prev;
        }
        *head = (*head)->next;
    }
	*head = keep;
	
	//printf("\nsorted = \n");
	//printlist(*head);

	stack->sorted = *head;

	return (1);
}

void	findmedian (t_stack *stack)
{
	stack1_t	*tmp;
	int			i;

	i = 0;
	tmp = stack->sorted;
	
	while (i < stack->size/2)
	{
		tmp = tmp->next;
		i++;
	}
	stack->median = tmp->value;

	i = 0;
	tmp = stack->sorted;
	
	while (i < stack->size/4)
	{
		tmp = tmp->next;
		i++;
	}
	stack->firstquart = tmp->value;

	i = 0;
	tmp = stack->sorted;
	
	while (i < stack->size - stack->size/4)
	{
		tmp = tmp->next;
		i++;
	}
	stack->thirdquart = tmp->value;

//	freelist(stack->sorted);
}

void	findhigherlower (stack1_t **head, t_stack *stack)
{
	stack1_t	*higher;
	stack1_t	*lower;
	stack1_t	*tmp;

	tmp = *head;
	higher = *head;
	lower = *head;
	while (*head != NULL)
	{
	//	if ((*head)->value > higher->value)
	//		higher = *head;
		if ((*head)->value > lower->value)
			lower = *head;
		*head = (*head)->next;
	}
	stack->lower = lower;
	stack->higher = higher;
	*head = tmp;
}

int		decidewhofirst(stack1_t **head, t_stack *stack, int i)
{
	stack1_t	*tmp;
	int			middle;
	int			j;
	int			ret;
	
	middle = i/2;
	j = 0;
	tmp = *head;

	stack->direction = 1;
	while (stack->lower->value != (*head)->value)
	{
		j++;
		*head = (*head)->next;
	}
	*head = tmp;

//	printf("\n***lower = %d_ j = %d***\n", stack->lower->value, j);
                                                          
	if (j > middle)
	{
		j = i - j;
		stack->direction = 2;
	}
		ret = j;
		return (ret);
}

void	flipit( stack1_t **headb, stack1_t **heada, t_stack *stack, int choose)
{
	int i;
//	int d;

//	d = 0;
	i = 0;
	
	if (stack->direction == 1)
	{
	/*	if ((*heada)->value > (*heada)->next->value && choose == 1)
		{
//			swapfirst(heada, 2, stack);
			swapfirst(headb, 0, stack);
//			printf("ss\n");
		} else
	*/	while ( i < choose)
		{
			i++;
	/*		if ((*heada)->value > (*heada)->next->value)
			{
				toptobottom(heada, 2, stack);
                        	toptobottom(headb, 2, stack);
                        	printf("rr\n");
				d++;
			} else
			{*/
				toptobottom (headb, 1, stack);
	
			}	
		}
	if (stack->direction == 2)
	{
		while ( i < choose)
		{
			i++;
			bottomtotop (headb, 1, stack); //faire un truc pour faire remonter le sbails?
		}
	}
/*	while ( d != 0)
	{
		bottomtotop(heada, 0, stack);
		d--;
	}
*/	givenode( headb, heada, 0, stack);
}

void	stackedbis(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	int i;
	int choose;
	int test;

	test = 0;
	i = 0;
	if(stack->size % 2 != 0)
			test++;
	while (i < stack->size/2 + test)
	{
		if ((*heada)->value <= stack->median)
		{
			givenode(heada, headb, 1, stack);
			i++;
		} else
	toptobottom(heada, 0, stack);
//	printf("coucou i = %d / median= %d / value = %d", i, stack->median, (*heada)->value);
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
}

void	stacked(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
//	stack1_t	*tmp;
	int			i;
	int			choose;
	int			test;

	test = 0;
	i = 0;
//	tmp = *heada;
	choose = stack->size;
//	tmp = *headb;
	choose = 0;
	
	//if(stack->size % 2 != 0)
		test++;
	while (i < stack->size/2 + test)
	{
		if ((*heada)->value >= stack->median)
		{
			givenode(heada, headb, 1, stack);
			i++;
		} else 
		toptobottom(heada, 0, stack);
	//	printf("coucou");
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);

		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
	stackedbis(heada, headb, stack);
}
