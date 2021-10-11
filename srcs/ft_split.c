/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:40:27 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/10/11 14:40:31 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pushswap.h"

static int	numstring(char const *s1, char c)
{
	int	num;
	int	rep;

	num = 0;
	rep = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			rep = 0;
		else if (rep == 0)
		{
			rep = 1;
			num++;
		}
		s1++;
	}
	return (num);
}

static int	sl(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**affect(char const *s, char **dst, char c, int p)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < p)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * (sl(s, c, i) + 1));
		if (!(dst[j]))
			return (NULL);
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		p;

	if (s == NULL)
		return (NULL);
	p = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (p + 1));
	if (!dst)
		return (NULL);
	return (affect(s, dst, c, p));
}
