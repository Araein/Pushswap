#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct stack1
{
	int				value;
	struct stack1	*next;
	struct stack1	*prev;
}			stack1_t;

typedef struct s_stack
{
	int			size;
	int			median;
	int			firstquart;
	int			thirdquart;
	int			therest;
	int			value;
	int			error;		
	int			one;	
	int			direction;
	int			operation;
	int			keep;
	int			j;
	int			min;
	int			max;
	stack1_t	*sorted;
	stack1_t	*higher;
	stack1_t	*lower;
}				t_stack;

void		printlist(stack1_t *head);
stack1_t	*createnode(int value);
stack1_t	*generatestack(int argc, char **argv, t_stack *stack);
stack1_t	*swapfirst(stack1_t **head, int boo, t_stack *stack);
void		givenode(stack1_t **head, stack1_t **head2, int boo, t_stack *stk);
int			countelem(stack1_t *head);
void		toptobottom(stack1_t **head, int boo, t_stack *stack);
void		bottomtotop(stack1_t **head, int boo, t_stack *stack);
void		triplechar(stack1_t **head, t_stack *stack);
void		firsttinier(stack1_t **head, t_stack *stack);
void		firstbigger(stack1_t **head, t_stack *stack);
long long	ft_atoi(const char *str);
void		fivechar(stack1_t **head, stack1_t **head2, int size, t_stack *stk);
int			sortstack(stack1_t **head, t_stack *stack);
void		findmedian(t_stack *stack);
void		findhigherlower(stack1_t **head, t_stack *stack);
int			decidewhofirst(stack1_t **head, t_stack *stack, int i);
void		flipit(stack1_t **hb, stack1_t **ha, t_stack *stack, int choose);
void		freelist(stack1_t **head);
char		**ft_split(char const *s, char c);
stack1_t	*listit(t_stack *stack, int size);
void		dealwithmore(stack1_t **heada, stack1_t **headb, t_stack *stack);
void		chungus(stack1_t **ha, stack1_t **hb, t_stack *stk, stack1_t **del);
void		last(stack1_t **ha, stack1_t **hb, t_stack *stk, stack1_t **del);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		checkdoublon(stack1_t **head, t_stack *stack);
int			littlenum(stack1_t **heada, stack1_t **sorted, t_stack *stack);
void		init(stack1_t **heada, stack1_t **headb, t_stack *stack);
int			launchit(stack1_t **ha, stack1_t **hb, stack1_t **st, t_stack *stk);
stack1_t	*error(char **splited, stack1_t *head);
void		checkerror(char **splited, int j, t_stack *stack);
void		finalstep(stack1_t **head, stack1_t **tmp, t_stack *stack);
void		switchies(int value, stack1_t **head);
#endif
