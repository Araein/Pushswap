#include "Pushswap.h"



int	findmedian( stack1_t **head, int size)
{
	//int			median;
	int			i;
	stack1_t	*tmp;
	stack1_t	*keep;
	i = 0;
	



	keep = *head;
	while (*head != NULL)
	{
		tmp = *head;
        while (tmp->next != NULL)//travel till the second last element 
        {
           if (tmp->value > tmp->next->value)// compare the data of the nodes 
            {
              i = tmp->value;
              tmp->value = tmp->next->value;// swap the data
              tmp->next->value = i;
            }
         tmp = tmp->next;    // move to the next element 
        } 
        while (tmp->prev != NULL)//travel till the second last element 
        {
           if (tmp->value > tmp->prev->value)// compare the data of the nodes 
            {
              i = tmp->value;
              tmp->value = tmp->prev->value;// swap the data
              tmp->prev->value = i;
            }
         tmp = tmp->prev;    // move to the next element 
        }
        *head = (*head)->next;    // move to the next node
    }

	printf("\n\ntosort = \n");
	*head = keep;
	printlist(*head);
	return (size);
}

/*





	return (median);
}*/
/*
stack1_t median (stack1_t *medin, stack1_t **head, size)
{
	stack1_t	*tmp;
	int			num;
	int			i;

	i = 0;
	num = size / 2;
	tmp = *head;

	while (i < size)
		*head = (*head)->next;
	median = *head;
	*head = tmp;
	return (median);
}

*/
/* tant aue moitie de size pas atteint, tout ce aui est < median go to ->b  le reste swap vers le bas de a*/

/*TRIER TEMPOSORT ET VOIR LA VALEUR MEDIANE*/


void stacked( stack1_t **head, stack1_t **head2, int size)
{
	int median;
	stack1_t *tt;

	median = findmedian(head, size);
	tt = *head2;
	



}
