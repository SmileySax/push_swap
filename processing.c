/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:46:24 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 02:53:46 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_presort(t_list **a, t_list **b, int l)
{
	int	i;
	int	flag;

	i = 0;
	while (*a)
	{
		flag = 0;
		if ((*a)->rank <= i + (-(13500 / (l + 270)) + 49) + 1)
		{
			pb(a, b);
			if ((*b)->rank < ++i - 1)
			{
				if (*a && (*a)->rank <= i + (-(13500 / (l + 270)) + 49) + 1)
					rb(b);
				else
				{
					rr(a, b);
					flag++;
				}
			}
		}
		else
			if (!flag)
				ra(a);
	}
}

int	ft_rb(int pos, int l, t_list **a, t_list **b)
{
	int	pos2;
	int	flag;

	flag = 0;
	pos2 = pos;
	if (l > 1)
		pos2 = ft_find_max_elem(*b, l - 1);
	if (pos > pos2 + 1)
	{
		flag++;
		while (pos2--)
		{
			pos -= 1;
			rb(b);
		}
		pa(a, b);
		rr(a, b);
		pos -= 2;
	}
	while (pos--)
		rb(b);
	return (flag);
}

int	ft_rrb(int pos, int l, t_list **a, t_list **b)
{
	int	flag;

	flag = 0;
	while (++pos <= l + 1)
	{
		if ((*b)->rank == l - 1)
		{
			pa(a, b);
			ra(a);
			flag++;
		}
		rrb(b);
	}
	return (flag);
}

void	ft_sort(t_list **a, t_list **b, int l)
{
	int	pos;
	int	flag;

	l--;
	while (l >= 0)
	{
		flag = 0;
		pos = ft_find_max_elem(*b, l);
		if (pos && pos <= l / 2)
			flag = ft_rb(pos, l, a, b);
		else if (pos && pos > l / 2)
			flag = ft_rrb(pos, l, a, b);
		l -= flag + 1;
		pa(a, b);
		if (flag)
		{
			pos = ft_find_max_elem(*b, l);
			if (pos && pos < l / 2)
				rra(a);
			else
				rrr(a, b);
		}
	}
}

void	ft_process(t_list **a, int argc)
{
	t_list	*b;

	b = NULL;
	if (argc <= 3)
		ft_process_3(a, argc);
	else if (argc <= 6)
		ft_process_6(a, &b, argc);
	else
	{
		ft_presort(a, &b, argc);
		ft_sort(a, &b, argc);
	}
}
