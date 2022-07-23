/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:45:42 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 03:18:08 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_elem(t_list *list, int l)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->rank == l)
			return (i);
		i++;
		list = list->next;
	}
	return (0);
}

int	ft_find_min_elem(t_list *list)
{
	int	i;
	int	min;
	int	p;

	i = 0;
	p = 0;
	min = list->rank;
	while (list)
	{
		if (list->rank < min)
		{
			min = list->rank;
			p = i;
		}
		i++;
		list = list->next;
	}
	return (p);
}

void	ft_process_3(t_list **a, int argc)
{
	int	c[3];

	if (argc == 2)
		ra(a);
	else
	{
		c[0] = (*a)->rank;
		c[1] = (*a)->next->rank;
		c[2] = (*a)->next->next->rank;
		if (((c[0] < c[1]) && (c[0] < c[2])) || (c[0] > c[1] && (((c[2] > c[1])
						&& (c[2] > c[0])) || ((c[2] < c[1]) && (c[2] < c[0])))))
			sa(a);
		if (c[2] < c[1] && c[2] < c[0])
			rra(a);
		else if ((c[2] < c[1] && c[2] > c[0]) || (c[2] > c[1] && c[2] < c[0]))
			ra(a);
	}
}

void	ft_process_6(t_list **a, t_list **b, int l)
{
	int	min;

	while (l > 3)
	{
		min = ft_find_min_elem(*a);
		if (min && min < l / 2)
			while (min--)
				ra(a);
		else if (min && min >= l / 2)
			while (++min < l + 1)
				rra(a);
		pb(a, b);
		l--;
	}
	if (!ft_is_sort(*a))
		ft_process_3(a, l);
	while (*b)
		pa(a, b);
}
