#include <stdlib.h>
#include <stdio.h>

struct stack1 {

	int value;
	struct stack1 *next;
};
typedef struct stack1 stack1_t;

struct stack2 {

	int value;
	struct stack2  *next;
};
typedef struct stack2 stack2_t;






/* PRINT LIST*/
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

/*CREATE NODE DYNAMICALLY*/

stack1_t *createnode (int value)
{
	stack1_t *result = malloc(sizeof(stack1_t));
	result->value = value;
	result->next = NULL;
	return (result);
}

stack1_t *generatestack(int i)
{

	stack1_t *head;
	stack1_t *tmp;
	int j;
	
	head = NULL;
	j = 0;
	tmp = createnode(j);
	while (j < i)
	{
		j++;
		tmp = createnode(j);
		tmp->next = head;
		head = tmp;
	}
	return (head);
}
int main ()
{
/*	stack1_t *head;
	stack1_t *tmp;
	int i;
	
	head = NULL;
	i = 0;
	tmp = createnode(i);
	while (i < 25)
	{
		i++;
		tmp = createnode(i);
		tmp->next = head;
		head = tmp;
	}
*/
/*

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
*/
	printlist(generatestack(10));


return (0);
}








