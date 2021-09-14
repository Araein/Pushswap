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
//	printlist(*head);

	return (1);
}

void	findmedian (t_stack *stack)
{
	stack1_t	*tmp;
	int			i;
	
	i = 0;
	tmp = stack->sorted;
	while (i < stack->size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	stack->median = tmp->value;
}


/* tant aue moitie de size pas atteint, tout ce aui est < median go to ->b  le reste swap vers le bas de a*/

/*TRIER TEMPOSORT ET VOIR LA VALEUR MEDIANE*/


void stacked(stack1_t **heada, stack1_t **headb, t_stack *stack)
{
	stack1_t	*tmp;
	int			i;
	/*push everything below the median into stack b. */
	i = 0;
	tmp = *heada;
	while ((*heada)->next != NULL && i < stack->size / 2)
	{
		if ((*heada)->value <= stack->median)
		{
			givenode(heada, headb, 1);
			i++;
		} else 
		toptobottom(heada, 0);
	}
}
