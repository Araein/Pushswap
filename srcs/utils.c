#include "Pushswap.h"

int	countelem(t_linked *head)
{
	int	i;

	if (head == NULL)
		return (0);
	i = 1;
	while (head->next != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	freelist(t_linked **head)
{
	t_linked	*tmp;

	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

long long	ft_atoi(const char *str)
{
	long long	signe;
	long long	i;
	long long	num;

	i = 0;
	signe = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * signe);
}
