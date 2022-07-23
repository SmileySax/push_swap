/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:23:34 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 02:35:00 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **begin_list)
{
	t_list	*list;
	t_list	*res;

	if (begin_list && *begin_list && (*begin_list)->next)
	{
		list = *begin_list;
		while (list->next)
		{
			res = list;
			list = list->next;
		}
		list->next = *begin_list;
		*begin_list = list;
		res->next = NULL;
	}
}

void	rra(t_list **begin_list)
{
	ft_reverse_rotate(begin_list);
	write(1, "rra\n", 4);
}

void	rrb(t_list **begin_list)
{
	ft_reverse_rotate(begin_list);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
