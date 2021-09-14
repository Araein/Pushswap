#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct	stack1
{
	int value;
	struct stack1 *next;
	struct stack1 *prev;
}				stack1_t;

/*ajouter structure avec nombre d'actions effectuees et taille de liste?*/
void printlist (stack1_t *head);
stack1_t *createnode (int value);
stack1_t *generatestack(int argc, char **argv);
stack1_t *swapfirst(stack1_t *head, int boo);
void givenode( stack1_t **head,  stack1_t **head2, int boo);
int countelem (stack1_t *head);
void toptobottom(stack1_t **head, int boo);
void bottomtotop(stack1_t **head, int boo);
void triplechar(stack1_t **head);
void firsttinier (stack1_t **head);
void firstbigger (stack1_t **head);
int ft_atoi(const char *str);
void fivechar(stack1_t **head, stack1_t **head2, int size);
void stacked(stack1_t **head, stack1_t **head2, int size);
int  findmedian (stack1_t **head, int size); 


#endif
