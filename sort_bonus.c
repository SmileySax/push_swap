/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:23:45 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 13:40:20 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_resort_tab(unsigned int **tab, int tab2[10], int l, int p)
{
	unsigned int	*tab3;

	tab3 = (unsigned int *)malloc(sizeof(unsigned int) * l);
	if (!tab3)
		return (-1);
	while (--l >= 0)
		tab3[(--tab2[(*tab)[l] / p % 10])] = (*tab)[l];
	free (*tab);
	*tab = tab3;
	return (0);
}

void	ft_find_min_and_normalize_to_tab(unsigned int **tab, int *min,
	t_list *begin_list, t_list **list)
{
	int	i;

	i = 0;
	*list = begin_list;
	*min = (*list)->data;
	while (*list)
	{
		if ((*list)->data < *min)
				*min = (*list)->data;
		*list = (*list)->next;
	}
	*list = begin_list;
	while ((*list)->next)
	{
		(*tab)[i++] = (unsigned int)((*list)->data - *min);
		*list = (*list)->next;
	}
	(*tab)[i] = (unsigned int)((*list)->data - *min);
}

int	ft_sort_tab(unsigned int **tab, int l)
{
	int	tab2[10];
	int	i;
	int	dec;
	int	p;

	dec = 0;
	p = 1;
	while (dec++ < 10)
	{
		i = 0;
		while (i < 10)
			tab2[i++] = 0;
		i = l;
		while (--i >= 0)
			tab2[(*tab)[i] / p % 10]++;
		while (++i < 9)
			tab2[i + 1] = tab2[i] + tab2[i + 1];
		if (ft_resort_tab(tab, tab2, l, p))
			return (-1);
		p *= 10;
	}
	return (0);
}

void	ft_ranking(t_list *begin_list, unsigned int **tab, int argc)
{
	int		l;
	t_list	*list;
	t_list	*last_list;
	int		min;

	ft_find_min_and_normalize_to_tab(tab, &min, begin_list, &list);
	l = argc;
	last_list = list;
	ft_sort_tab(tab, argc);
	last_list->next = begin_list;
	l--;
	while (l >= 0)
	{
		if (list->data == (int)((long)(*tab)[l] + min))
			list->rank = l--;
		list = list->next;
	}
	last_list->next = NULL;
}

int	ft_sort_n_check(t_list *begin_list, int *err, int argc)
{
	unsigned int	*tab;

	tab = (unsigned int *)malloc(sizeof(unsigned int) * argc);
	if (!tab)
		return (0);
	ft_ranking(begin_list, &tab, argc);
	return (ft_is_uniq(tab, argc, err));
}
