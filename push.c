/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:23:13 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 02:54:14 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **from, t_list **to)
{
	t_list	*res;

	if (from && to && *from)
	{
		res = *from;
		*from = (*from)->next;
		if (!*to)
			res->next = NULL;
		else
			res->next = *to;
		*to = res;
	}
}

void	pb(t_list **begin_list_a, t_list **begin_list_b)
{
	ft_push(begin_list_a, begin_list_b);
	write(1, "pb\n", 3);
}

void	pa(t_list **begin_list_a, t_list **begin_list_b)
{
	ft_push(begin_list_b, begin_list_a);
	write(1, "pa\n", 3);
}
