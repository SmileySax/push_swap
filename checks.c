/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:19:36 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 03:13:28 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numreader(char *arg, int *err, int p)
{
	long	num;

	num = 0;
	if (*arg)
	{
		while (*arg)
		{
			if ((*arg >= '0') && (*arg <= '9'))
				num = num * 10 + p * (*(arg++) - '0');
			else
			{
				*err = 1;
				break ;
			}
		}
	}
	if (*err == 1)
		return (num);
	if (num != (int)num)
		*err = 1;
	return ((int)num);
}

int	ft_err_atoi(char *arg, int *err)
{
	int	num;
	int	p;

	num = 0;
	p = 1;
	if (*arg)
	{
		if (*arg == '-')
		{
			p = -1;
			arg++;
		}
		num = ft_numreader(arg, err, p);
	}
	else
		*err = 1;
	return (num);
}

int	ft_is_uniq(unsigned int *tab, int i, int *err)
{
	while (--i)
	{
		if (tab[i] == tab[i - 1])
		{
			*err = 1;
			free(tab);
			return (0);
		}
	}
	free(tab);
	return (1);
}

int	ft_is_sort(t_list *begin_list)
{
	t_list	*list;

	list = begin_list;
	while (list->next && list->data < list->next->data)
		list = list->next;
	if (list->next)
		return (0);
	else
		return (1);
}
