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
		i++;

        }
	head->next = NULL;
	while (head->prev != NULL)
	{
		head = head->prev;
        }
	return (head);
}   //pas oublier de free la liste cree


void    lastchungus(stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **delimiter)
{
        stack1_t	      *tmp;
        int                     i;
        int                     choose;
	int			j;
//	int			d;


//	d = 0;
        i = 0;
        choose = 0;
	j = 0;
	tmp = *heada;

	while (tmp->next != NULL)
		tmp = tmp->next;


	int d;

	d = 0;

        while ( i < 2)
        {

                if ( tmp->value <= (*delimiter)->value)
                        d++;
                tmp = tmp->prev;
                i++;
        }
        if ( d > 0)
        {
                while (i > 0)
                {
                        i--;
                        bottomtotop(heada, 0, stack);
                }
        }

        i = 0;
        d = 0;
        tmp = *heada;
        while (tmp->next != NULL)
                tmp = tmp->next;

j = 0;


        while (i < stack->size - stack->keep)
        {
                if ((*heada)->value <= (*delimiter)->value)
                {
                        givenode(heada, headb, 1, stack);
                        i++;
                } else if (i > 1 && (*headb)->value < (*headb)->next->value)
                {
                        toptobottom(heada, 2, stack);
                        toptobottom(headb, 2, stack);
                        printf("rr\n");
                } else if ( (j == 0 || i == 0) && tmp->value <= (*delimiter)->value)
		{
			tmp = tmp->prev;
			bottomtotop(heada, 0, stack);
		}else
			toptobottom(heada, 0, stack);
	       	j++;
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

void	chungus( stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **delimiter)
{
	stack1_t		*tmp;
	int			i;
	int			choose;
	int 			j;
	int			d;

	d = 0;
	i = 0;
	j = 0;
	choose = 0;
	tmp = *heada;

	while (tmp->next != NULL)
		tmp = tmp->next;
while (j < 20)
{

	while ( i < 2)
	{

		if ( tmp->value > (*delimiter)->value && ((*delimiter)->prev == NULL || tmp->value <= (*delimiter)->prev->value))
			d++;	
		tmp = tmp->prev;
		i++;
	}
	if ( d > 0)
	{
		while (i > 0)
		{
			i--;
			bottomtotop(heada, 0, stack);
		}
	}

	i = 0;
	d = 0;
	tmp = *heada;
	while (tmp->next != NULL)
		tmp = tmp->next;

	j++;
}
j = 0;

	while (i < stack->size / 8) //ATTENTION
	{
		if ((*heada)->value > (*delimiter)->value && ((*delimiter)->prev == NULL || (*heada)->value <= (*delimiter)->prev->value))
		{
			givenode(heada, headb, 1, stack);
			i++;
			stack->keep++;
		} else if (i > 1 && (*headb)->value < (*headb)->next->value)
		{
			toptobottom(heada, 2, stack);
			toptobottom(headb, 2, stack);
			printf("rr\n");
		} else if ( (j == 0 || i == 0) && (tmp)->value > (*delimiter)->value && ((*delimiter)->prev == NULL || (tmp)->value     <= (*delimiter)->prev->value))
		{
			tmp = tmp->prev;
			bottomtotop(heada, 0, stack);
		} else
		toptobottom(heada, 0, stack);
		
		j++;
	}
	while ((*headb)->next != NULL)
	{
		findhigherlower(headb, stack);
		choose = decidewhofirst(headb, stack, i);
		flipit(headb, heada, stack, choose);
		i--;
//		stack->keep++;
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
	stack->keep = 0;


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

