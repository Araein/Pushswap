#include "Pushswap.h"


void	freelist(stack1_t **head)
{
	stack1_t *tmp;

	while ((*head)->prev != NULL)
		*head = (*head)->prev;
   while (*head != NULL)
    {
       tmp = *head;
       *head = (*head)->next;
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

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
//	printf("\ni = %d", i);

	return (i);

}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


int	ft_isdigit(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

stack1_t *generatestack(int argc, char **argv, t_stack *stack)
{

	stack1_t *head;
	stack1_t *tmp;
	char	**splited;
	int j;
	int d;

	d = 0;

	head = NULL;
	while (argc > 1)
	{
		splited = ft_split(argv[argc - 1], ' ');
		j = tablen(splited);
	while (j >= 1)
        {
		if (!(ft_isdigit(splited[j - 1])))
			stack->error = 1;	
		if (stack->error == 0 && (ft_atoi(splited[j - 1]) > 2147483647 || ft_atoi(splited[j - 1]) < -2147483648))
			stack->error = 1;
		if (stack->error == 1)
		{
			freetab(splited);
			return (head);
		}
	//	stack->one = 0;
		tmp = createnode(ft_atoi(splited[j - 1]));
                tmp->next = head;
                if (d > 0)
                        head->prev = tmp;
                head = tmp;
                j--;
		d++;
        }
		freetab(splited);
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
