#include "Pushswap.h"

stack1_t	*listit(t_stack *stack, int size) //cree une lsite chainee contenant les splits 
{
	stack1_t	*tmp;
	stack1_t	*ref;
	stack1_t	*head;
	int		i;
	int		j;

	j = 0;
	stack->value = stack->size / size;
	stack->therest = stack->size % size; 
	i = 0;
	ref = stack->sorted;

	while (i < size - 1)
        {                
		j = 0;
		while (j < stack->value)
		{
			j++;
			ref = ref->next;
		}
		if (i == 0)
			head = createnode(ref->value);
		else
		{
			tmp = createnode(ref->value);
			head->next = tmp;
			tmp->prev = head;
			head = head->next;
			head->next = NULL;
		 }		
		i++;

        }
	head->next = NULL;
	while (head->prev != NULL)
		head = head->prev;
	return (head);
}


void    lastchungus(stack1_t **heada, stack1_t **headb, t_stack *stack, stack1_t **delimiter)
{
	stack1_t	*tmp;
	int			i;
	int			choose;
	int			j;

	i = 0;
	choose = 0;
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
                        ft_putstr("rr\n");
                } else if ( (j == 0 || i == 0) && tmp->value <= (*delimiter)->value)
		{
			tmp = tmp->prev;
			bottomtotop(heada, 0, stack);
		}else
			toptobottom(heada, 0, stack);
	       	j++;
        }
  i = countelem(*headb);
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
	int 			j;

	i = 0;
	j = 0;
	tmp = *heada;

	while (tmp->next != NULL)
		tmp = tmp->next;

j = 0;

	while (i < stack->size / stack->one)
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
			ft_putstr("rr\n");
		} else if ( (j == 0 || i == 0) && (tmp)->value > (*delimiter)->value && ((*delimiter)->prev == NULL || (tmp)->value     <= (*delimiter)->prev->value))
		{
			tmp = tmp->prev;
			bottomtotop(heada, 0, stack);
		} else
		toptobottom(heada, 0, stack);
		
		j++;
	}

i = countelem(*headb);

	*delimiter = (*delimiter)->next;
}




void	dealwithmore(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*delimiter;
	int 		i;
	stack1_t	*tmp;
	stack1_t	*tmp2;
	
//	stack->one = 11;
	i = 0;
	delimiter = listit(stack, stack->one);   
	tmp = delimiter;
    tmp2 = delimiter;
	while(tmp->next != NULL)
		tmp = tmp->next;
	stack->keep = 0;

	delimiter->prev = NULL;
	while( i < stack->one - 1)
	{
		chungus(heada, headb, stack, &delimiter);
		i++;
	}
	lastchungus(heada, headb, stack, &tmp);

	freelist(tmp2);
	/*freedelimiter*/
}

