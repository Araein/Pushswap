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

int main ()
{
	stack1_t n1, n2, n3, n4;
	stack1_t *head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;
	n4.value = 89;

	head = &n1;
	n1.next = &n4;
	n4.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	printlist(head);


return (0);
}








