/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:27:02 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 02:29:40 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **begin_list)
{
	t_list	*res;

	if (begin_list && *begin_list && (*begin_list)->next)
	{
		res = (*begin_list)->next;
		(*begin_list)->next = (*begin_list)->next->next;
		res->next = (*begin_list);
		*begin_list = res;
	}
}

void	sa(t_list **begin_list)
{
	ft_swap(begin_list);
	write(1, "sa\n", 3);
}

void	sb(t_list **begin_list)
{
	ft_swap(begin_list);
	write(1, "sb\n", 3);
}

void	ss(t_list **begin_list_a, t_list **begin_list_b)
{
	ft_swap(begin_list_a);
	ft_swap(begin_list_b);
	write(1, "ss\n", 3);
}
