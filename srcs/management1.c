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
	int i;

	i = 0;
	head = NULL;
	j = argc; 
	
		
	j = 0;
	argv = ft_split(argv[1], ' ');

	while(argv[i])
		i++;
	j = i;
	while (i > 0)
	{
		tmp = createnode(ft_atoi(argv[i - 1]));
		tmp->next = head;
		if ( i < j)
			head->prev = tmp;
		head = tmp;
		i--;
	}
/*
	while (argc > 1)
	{
		tmp = createnode(ft_atoi(argv[argc - 1]));
		tmp->next = head;
		if (argc < j)
			head->prev = tmp;
		head = tmp;
		argc--;
	}
*/	return (head);
}
stack1_t *swapfirst(stack1_t *head, int boo, t_stack *stack)
{
	int i;

	i = head->next->value;
	head->next->value = head->value;
	head->value = i;
	if (boo == 1) 
		printf("sb\n");
	if (boo == 2)
		printf("ss\n");
	else
		printf("sa\n");
	stack->operation += 1;
	return (head);

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
		printf("pb\n");
	else
		printf("pa\n");
	stack->operation += 1;
}
