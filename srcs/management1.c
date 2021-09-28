#include "Pushswap.h"


void	freelist(stack1_t *head)
{
   stack1_t *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}
/*
void printlist (stack1_t *head)
{
	stack1_t *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
*/
stack1_t *createnode (int value)
{
	stack1_t *result = malloc(sizeof(stack1_t));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

stack1_t *generatestack(int argc, char **argv)
{

	stack1_t *head;
	stack1_t *tmp;
	int j;

	head = NULL;
	j = argc; 

	while (argc > 1)
	{
		tmp = createnode(ft_atoi(argv[argc - 1]));
		tmp->next = head;
		if (argc < j)
			head->prev = tmp;
		head = tmp;
		argc--;
	}
	return (head);
}
stack1_t *swapfirst(stack1_t **head, int boo, t_stack *stack)
{
	stack1_t *tmp;
	stack1_t *tmp2;


	tmp = *head;
	tmp2 = (*head)->next;


	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->prev = NULL;
	tmp2->next = tmp;
	*head = tmp2;
	if ((*head)->next->next != NULL)
		(*head)->next->next->prev = (*head)->next;
	if (boo == 1) 
		ft_putstr("sb\n");
	if (boo == 2)
		return (*head);
	else
		ft_putstr("sa\n");
	stack->operation += 1;
	return (*head);

}

void givenode( stack1_t **head,  stack1_t **head2, int boo, t_stack *stack)
{
	stack1_t *tmp;

	if (countelem (*head) == 0)
			return ;
	tmp = *head;
	if (countelem (*head) > 1)
		(*head)->next->prev = NULL;
	*head = (*head)->next;
	
	if (*head2 == NULL)
	{
		*head2 = tmp;
		(*head2)->next = NULL;
		(*head2)->prev = NULL;
	}
	else
	{	
		tmp->next = *head2;
		(*head2)->prev = tmp;
		*head2 = tmp;
	}
	if (boo == 1) 
		ft_putstr("pb\n");
	else
		ft_putstr("pa\n");
	stack->operation += 1;
}
