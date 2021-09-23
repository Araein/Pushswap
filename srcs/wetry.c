#include "Pushswap.h"

stack1_t	*listit(t_stack *stack, int size) //cree une lsite chainee contenant les splits 
{
	stack1_t	*tmp;
	stack1_t	*ref;
	stack1_t	*head;
	int		i;
//	int		value;
	int		j;

	j = 0;
	stack->value = stack->size / size;
	stack->therest = stack->size % size; 
	i = 0;
	ref = stack->sorted;
//	printlist(ref);  
	//     printf("\nvalue = %d / j = %d", stack->value, j);

	//head = NULL;
	while (i < size - 1)
        {                
      // printf("\nheyboss!\n");

		j = 0;
		while (j < stack->value)
		{
	//	       printf("\nheyboss!\n");
          // printf("\nvalue = %d / j = %d\n", stack->value, j);

			j++;
			ref = ref->next;
//  printf("\nCOUCOU\n");
		}
//		printf("\nCOUCOU\n");
		if (i == 0)
			head = createnode(ref->value);
		else
		{
		
			tmp = createnode(ref->value);
//			printf("\nhead value = %d // tmp->value = %d\n", head->value, tmp->value);
			head->next = tmp;
			tmp->prev = head;
//			tmp = head;
			head = head->next;
			head->next = NULL;
		 }		
//		printf("\nheyboss!\n");
/*		if (i > 0)
			head->prev = tmp;
		else
			head->prev = NULL;
*/
		i++;
//printf("\nheyboss!\n");

        }
//	printf("\nheyboss!\n");

	head->next = NULL;
	while (head->prev != NULL)
	{
		head = head->prev;
        }

//	printlist(head);
//	printf("\ncoucou\n");
	return (head);
}   //pas oublier de free la liste cree


void    lastchungus(stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **delimiter)
{
        //stack1_t      *tmp;
        int                     i;
        int                     choose;
	int			j;

        i = 0;
        choose = 0;
//      stack->value = 
//      stack->keep = stack->size;
	j = 0;
//	printf("\nstack->size = %d // rest : %d // delimiter : %d\n", stack->size, stack->therest, 0/*(*delimiter)->preva->value*/);

        while (j < stack->size/* + stack->therest*/)
        {
                if ((*heada)->value <= (*delimiter)->value)
                {
                        givenode(heada, headb, 1, stack);
                        i++;
//                      stack->keep--;
                } else if (i > 1 && (*headb)->value < (*headb)->next->value)
                {
                        toptobottom(heada, 2, stack);
                        toptobottom(headb, 2, stack);
                        printf("rr\n");
                } else
           	{
		   	toptobottom(heada, 0, stack);
		} 
	       	j++;
	
	
		//      printf("\ni = %d stack = %d coucou \n", i, stack->value);
        }
//	j = j - i;
/*	while (j > 0)
	{
		bottomtotop(heada, 0, stack);
		j--;
	}
*/
        while ((*headb)->next != NULL)
        {
                findhigherlower(headb, stack);
                choose = decidewhofirst(headb, stack, i);
                flipit(headb, heada, stack, choose);
                i--;
        }
        givenode(headb, heada, 0, stack);
  //      *delimiter = (*delimiter)->next;
}

void	chungus( stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **delimiter)
{
	//stack1_t	*tmp;
	int			i;
	int			choose;
	int 			j;

	i = 0;
	j = 0;
	choose = 0;
//	stack->value = 
//	stack->keep = stack->size;
	
	while (j < stack->size && i < stack->size / 8) //ATTENTION
	{
		if ((*heada)->value > (*delimiter)->value && ((*delimiter)->prev == NULL || (*heada)->value <= (*delimiter)->prev->value))
		{
			givenode(heada, headb, 1, stack);
			i++;
//			stack->keep--;
		} else if (i > 1 && (*headb)->value < (*headb)->next->value)
		{
			toptobottom(heada, 2, stack);
			toptobottom(headb, 2, stack);
			printf("rr\n");
		} else
		toptobottom(heada, 0, stack);
	//	printf("i = %d stack = %d coucou ", i, stack->value);
		j++;
	}


//	printlist(*heada);
//	printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
//	printlist(*headb);
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
	}
	givenode(headb, heada, 0, stack);
//	printf("\ndelimiter = %d\n", (*delimiter)->value);
	*delimiter = (*delimiter)->next;
}

void	dealwithmore(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*delimiter;
	int 		i;
	stack1_t	*tmp;

	i = 0;
	delimiter = listit(stack, 8);   //premier element est le plus grand
	tmp = delimiter;
        while(tmp->next != NULL)
        	tmp = tmp->next;
	
	delimiter->prev = NULL;
//	printlist (delimiter);
//	printf("stack->value = %d ", stack->value);
	while( i < 7)
	{
//		printf("\nheyboss!\n");
		chungus(heada, headb, stack, &delimiter);
//		printf("\nisitbetter? i = %d\n", i);
//		printlist(*heada);
		i++;
	}
//	printf("y\neeeeeeeeeee\n");
	lastchungus(heada, headb, stack, &tmp);
//	printlist(*heada);

	/*REFAIRE UN ROUND AVEC LE RESTE*/
	/*freedelimiter*/
}

