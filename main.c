#include "Pushswap.h"


int main ()
{
	stack1_t *head;
	stack1_t *head2;
	stack1_t *head3;
	head = generatestack(10);
	
	head2 = generatestack(10);
	head3 = generatestack(10);

	bottomtotop(&head2);
	toptobottom(&head3);
	givenode(&head, &head2);

	printf("\n--------------- head :\n");
	printlist(head);
//	printf("\n head a %d elem", countelem(head));
	printf("\n--------------- head2 bottomtotop :\n");
	printlist(head2);
	printf("\n--------------- head3 toptobottom :\n");
	printlist(head3);


//	printf("\n head2 a %d elem", countelem(head2));


	return (0);
}
