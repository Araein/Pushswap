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

void toptobottom(stack1_t **head)
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
}

void bottomtotop(stack1_t **head)
{
	stack1_t *tmp;
	stack1_t *tmp2;
	
	while ((*head)->next != NULL)
		*head = (*head)->next;
	tmp2 = *head;
	tmp = (*head)->prev;
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	tmp->next = NULL;
	tmp2->prev = NULL;
	(*head)->prev = tmp2;
	tmp2->next = *head;
	*head = tmp2;
}
