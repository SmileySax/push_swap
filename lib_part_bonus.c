/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_part_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:38:04 by keaton            #+#    #+#             */
/*   Updated: 2022/07/22 21:42:37 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_create_elem(int num)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = 0;
	list->data = num;
	list->rank = 0;
	return (list);
}

t_list	*ft_lstadd_front(t_list *lst, int num)
{
	t_list	*new;

	if (!lst)
		return (ft_create_elem(num));
	new = ft_create_elem(num);
	if (!new)
	{
		ft_free_lst(&lst);
		return (NULL);
	}
	new->next = lst;
	return (new);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n && (unsigned char)s1[i] != '\0')
		i++;
	if (i == n)
		return (1);
	return (0);
}

void	ft_free_lst(t_list **lst)
{
	t_list	*free_list;

	if (lst)
	{
		while (*lst)
		{
			free_list = *lst;
			*lst = free_list->next;
			if (*lst)
				free_list->next = 0;
			free(free_list);
		}
	}
}
