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
	stack->sorted = *head;
	printlist(*head);

	return (1);
}

void	findmedian (t_stack *stack)
{
	stack1_t	*tmp;
	int			i;
	
	i = 0;
	tmp = stack->sorted;
//	if (stack->size % 2 != 0)
		
	while (i < stack->size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	stack->median = tmp->value;
}


/* tant aue moitie de size pas atteint, tout ce aui est < median go to ->b  le reste swap vers le bas de a*/

/*TRIER TEMPOSORT ET VOIR LA VALEUR MEDIANE*/


void	findhigherlower (stack1_t **head, t_stack *stack)
{
	stack1_t	*higher;
	stack1_t	*lower;
	stack1_t	*tmp;


	//i = nombre d'elements dans b
	/*trouve le nombre le plus petit et le plus grand dans b*/
	tmp = *head;
	higher = *head;
	lower = *head;
	while (*head != NULL)
	{
	//	if ((*head)->value > higher->value)
	//		higher = *head;
		if ((*head)->value < lower->value)
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
	int			k;
	int			jtemp;
	int			ktemp;
	int			ret;
	
//	i = countelem(*head);
	middle = i/2;
	j = 0;
	k = 0;
	tmp = *head;

//	jtemp = j;
	ktemp = k;

	stack->direction = 1;
//	printf("\n***lower = %d_ j = %d / head value = %d***\n", stack->lower->value, j, (*head)->value);
	while (stack->lower->value != (*head)->value)
	{
		j++;
		*head = (*head)->next;
	}
	*head = tmp;

	printf("\n***lower = %d_ j = %d***\n", stack->lower->value, j);
	jtemp = j;
	/*	while (stack->higher->value != (*head)->value)
	{
		k++;
		*head = (*head)->next;
	}
	*head = tmp;
*/	     
//	printf("\nCOUCOU\n");                                                          
	if (j > middle)
	{
		j = i - j;
		stack->direction = 2;
	}
		/*	if (k > middle)
		k = k - middle;
	if (j < k)
	{
*/	//	if (jtemp >= middle)
	//	{
	//		stack->direction = 2;
	//		j--;
	//	}
			
		ret = j;
//		if (stack->direction == 2)
//			ret--;
//		if ( ret < 0)
//			ret = 0;

		
		/*	}
	else
	{
		if (ktemp > middle)
			stack->direction = 2;
		ret = k;
	}
*/
		printf("ret = %d\n", ret);
		return (ret);    /*trie qui sera le prochain elem a etre flip*/
	
}

void	flipit( stack1_t **headb, stack1_t **heada, t_stack *stack, int choose)
{
	int i;
	
//	printf("\nCOUCOU\n");
	i = 0;
	if (stack->direction == 1)
	{
		while ( i < choose)
		{
			i++;
			toptobottom (headb, 1);
		}
	}
	if (stack->direction == 2)
	{
		while ( i < choose)
		{
			i++;
			bottomtotop (headb, 1);
		}
	}
	givenode( headb, heada, 0);
}


void	stacked(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*tmp;
	int			i;
	int			choose;
	int			test;

	test = 0;
	/*push everything below the median into stack b. */
	i = 0;
	tmp = *heada;
	printf("\n sizetotale = %d", stack->size);
	if(stack->size % 2 != 0)
		test++;


	while (/*(*heada)->next != NULL &&*/ i < stack->size/2 + test)  /*quand nombre impair ca casse les couilles*/
	{
		if ((*heada)->value <= stack->median)
		{
			givenode(heada, headb, 1);
			i++;
		} else 
		toptobottom(heada, 0);
	}
//	printf ("\n///////////b////////////\n");
//	printlist(*headb);
	while ((*headb)->next != NULL)
	{
		
		printf ("\n///////////b////////////\n");
	//	printlist(*headb);
	
		findhigherlower(headb, stack);

		choose = decidewhofirst(headb, stack, i); //direction  2 = rrb 1 = rb
		printf("\n\nchoose = %d || direction = %d\n\n", choose, stack->direction);
		flipit(headb, heada, stack, choose);
		i--;
		//diminuer i?
	}
	givenode(headb, heada, 0);
}
