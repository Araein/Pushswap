#include "Pushswap.h"

int countelem (stack1_t *head)
{
	int i;
	
	if (head == NULL)
		return (0);
	i = 1;
	while (head->next != NULL)
	{
		i++;		
		head = head->next;
	}
	return i;
}

void toptobottom(stack1_t **head, int boo, t_stack *stack)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	
	tmp = *head;
	tmp2 = (*head)->next;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	while ((*head)->next != NULL)
		*head = (*head)->next;	
	tmp->prev = *head;
	tmp->next = NULL;
	(*head)->next = tmp;
	*head = tmp2;
	if (boo == 1)
		printf("rb\n");
	if (boo == 2)
		return ;
	if (boo == 0)
		printf("ra\n");
	stack->operation += 1;
}

void bottomtotop(stack1_t **head, int boo, t_stack *stack)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	
//	printf("btt = %d\n", (*head)->next->value);
	while ((*head)->next != NULL)
		*head = (*head)->next;
//	printf("btt = %d\n", (*head)->prev->value);
	
	
	tmp2 = *head;
	tmp = (*head)->prev;
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	tmp->next = NULL;
	tmp2->prev = NULL;
	(*head)->prev = tmp2;
	tmp2->next = *head;
	*head = tmp2;
	if (boo == 1)
		printf("rrb\n");
	if (boo == 2)
		return ;
	if (boo == 0)
		printf("rra\n");
	stack->operation += 1;
}
