/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:22:20 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 15:22:23 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}			t_linked;

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
	t_linked	*sorted;
	t_linked	*higher;
	t_linked	*lower;
}				t_stack;

void		printlist(t_linked *head);
t_linked	*createnode(int value);
t_linked	*generatestack(int argc, char **argv, t_stack *stack);
t_linked	*swapfirst(t_linked **head, int boo, t_stack *stack);
void		givenode(t_linked **head, t_linked **head2, int boo, t_stack *stk);
int			countelem(t_linked *head);
void		toptobottom(t_linked **head, int boo, t_stack *stack);
void		bottomtotop(t_linked **head, int boo, t_stack *stack);
void		triplechar(t_linked **head, t_stack *stack);
void		firsttinier(t_linked **head, t_stack *stack);
void		firstbigger(t_linked **head, t_stack *stack);
long long	ft_atoi(const char *str);
void		fivechar(t_linked **head, t_linked **head2, int size, t_stack *stk);
int			sortstack(t_linked **head, t_stack *stack);
void		findmedian(t_stack *stack);
void		findhigherlower(t_linked **head, t_stack *stack);
int			decidewhofirst(t_linked **head, t_stack *stack, int i);
void		flipit(t_linked **hb, t_linked **ha, t_stack *stack, int choose);
void		freelist(t_linked **head);
char		**ft_split(char const *s, char c);
t_linked	*listit(t_stack *stack, int size);
void		dealwithmore(t_linked **heada, t_linked **headb, t_stack *stack);
void		chungus(t_linked **ha, t_linked **hb, t_stack *stk, t_linked **del);
void		last(t_linked **ha, t_linked **hb, t_stack *stk, t_linked **del);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		checkdoublon(t_linked **head, t_stack *stack);
int			littlenum(t_linked **heada, t_linked **sorted, t_stack *stack);
void		init(t_linked **heada, t_linked **headb, t_stack *stack);
int			launchit(t_linked **ha, t_linked **hb, t_linked **st, t_stack *stk);
t_linked	*error(char **splited, t_linked *head);
void		checkerror(char **splited, int j, t_stack *stack);
void		finalstep(t_linked **head, t_linked **tmp, t_stack *stack);
void		switchies(int value, t_linked **head);

void		switchies( int value, t_linked **head);
t_linked	*listit(t_stack *stack, int size);
void		rrfunc(t_linked	**heada, t_linked **headb, t_stack *stack);
void		tril(t_linked **heada, t_linked **headb, t_stack *stack, t_linked **del);
void		last(t_linked **heada, t_linked **headb, t_stack *stack, t_linked **del);

int		tablen(char **tab);
void		freetab(char **tab);
int		ft_isdigit(char *nb);
t_linked	*error(char **splited, t_linked *head);
void		checkerror(char **splited, int j, t_stack *stack);

int		justincase(t_linked **head, t_linked *tmp, t_stack *stack);
void		dominmax(t_linked **ha, t_linked *tmp, t_linked *tmp2, t_stack *stack);
int		doublettob(t_linked **heada, t_stack *stack);
int		btotorttob(t_linked **heada, t_stack *stack, int i);
int		output(t_linked **heada, t_linked *tmp2, t_stack *stack);

void		movetmp(t_linked **tmp, t_linked **tmp2, t_linked **head);
void		finishthejob(t_linked **head, t_stack *stack);
void		doj(t_linked **head, t_linked **head2, t_stack *stack, int d);
void		toptop(t_linked **head, t_linked **head2, t_stack *stack);
void		botortop(t_linked **head, t_linked **head2, t_stack *stack, int i);
int		doesitfit(t_linked **heada, t_linked **headb, int d, t_stack *stack);
void		swapthem(t_linked **tmp, int d);

#endif
