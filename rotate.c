/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:23:24 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 02:51:13 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **begin_list)
{
	t_list	*list;
	t_list	*res;

	if (begin_list && *begin_list && (*begin_list)->next)
	{
		res = (*begin_list)->next;
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = *begin_list;
		(*begin_list)->next = NULL;
		*begin_list = res;
	}
}

void	ra(t_list **begin_list)
{
	ft_rotate(begin_list);
	write(1, "ra\n", 3);
}

void	rb(t_list **begin_list)
{
	ft_rotate(begin_list);
	write(1, "rb\n", 3);
}

void	rr(t_list **begin_list_a, t_list **begin_list_b)
{
	ft_rotate(begin_list_a);
	ft_rotate(begin_list_b);
	write(1, "rr\n", 3);
}
