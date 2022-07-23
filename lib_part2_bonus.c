/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_part2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:21:59 by keaton            #+#    #+#             */
/*   Updated: 2022/04/01 23:03:18 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_readword(char *s, int *i, char c)
{
	int	len;

	len = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	return (ft_substr(s, *i - len, len));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*mplace;
	int		slen;

	if (!s)
		return (NULL);
	l = 0;
	slen = (unsigned int)ft_strlen(s);
	while (start < (unsigned int)slen && (s + start)[l] && l < len)
		l++;
	mplace = malloc(sizeof(char) * (l + 1));
	if (!(mplace))
		return (NULL);
	mplace[l] = '\0';
	while (l > 0)
	{
		mplace[l - 1] = (char)(s + start)[l - 1];
		l--;
	}
	return (mplace);
}

int	ft_countwords(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		n;
	int		n1;
	char	**splited;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_countwords(s, c);
	n1 = 0;
	splited = (char **)malloc(sizeof(s) * (n + 1));
	if (!splited)
		return (NULL);
	splited[n] = (void *)0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (splited);
		splited[n1++] = ft_readword(s, &i, c);
		if (!splited[n1 - 1])
			return (ft_free_tab(splited));
	}
	return (splited);
}
