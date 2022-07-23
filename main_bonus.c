/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:55:37 by keaton            #+#    #+#             */
/*   Updated: 2022/07/22 21:51:14 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_stack_creation(int argc, char **argv, int *err)
{
	t_list	*begin_list;
	int		num;
	int		n;

	begin_list = NULL;
	n = argc;
	while (n > 0)
	{
		num = ft_err_atoi(argv[--n], err);
		begin_list = ft_lstadd_front(begin_list, num);
	}
	if (!begin_list)
		return (NULL);
	if (!ft_sort_n_check(begin_list, err, argc) || *err)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (begin_list);
}

int	ft_arg_one(int *argc, char ***argv, int *err)
{
	int		flag;

	flag = 0;
	if (*argc == 1)
	{
		while ((*argv)[0][*err])
		{
			if ((*argv)[0][(*err)++] == ' ')
			{
				*argc = ft_countwords((*argv)[0], ' ');
				*argv = ft_split((*argv)[0], ' ');
				if (!*argv)
				{
					write(2, "Error\n", 6);
					exit (0);
				}
				flag = 1;
				break ;
			}
		}
	}
	return (flag);
}

int	ft_exec_cmd(char **cmd, t_list **a, t_list **b)
{
	if (ft_strncmp(*cmd, "sa", 2))
		sa(a);
	else if (ft_strncmp(*cmd, "sb", 2))
		sb(b);
	else if (ft_strncmp(*cmd, "ss", 2))
		ss(a, b);
	else if (ft_strncmp(*cmd, "ra", 2))
		ra(a);
	else if (ft_strncmp(*cmd, "rb", 2))
		rb(b);
	else if (ft_strncmp(*cmd, "rra", 3))
		rra(a);
	else if (ft_strncmp(*cmd, "rrb", 3))
		rrb(b);
	else if (ft_strncmp(*cmd, "rrr", 3))
		rrr(a, b);
	else if (ft_strncmp(*cmd, "rr", 2))
		rr(a, b);
	else if (ft_strncmp(*cmd, "pa", 2))
		pa(a, b);
	else if (ft_strncmp(*cmd, "pb", 2))
		pb(a, b);
	else
		return (1);
	return (0);
}

void	ft_exec_and_check(char **cmd, t_list **a)
{
	t_list *b;

	b = NULL;
	*cmd = (char *)malloc(4);
	if (!(*cmd))
		exit (1);
	while (*cmd)
	{
		free(*cmd);
		*cmd = get_next_line(0);
		if (*cmd)
			if (ft_exec_cmd(cmd, a, &b))
				write(1, "Error\n", 6);
	}
	if (*cmd)
		free(*cmd);
	if (ft_is_sort(*a) && !b)
		write(1, "OK\n", 2);
	else
		write(1, "KO\n", 2);
	if (*a)
		ft_free_lst(a);
	if (b)
		ft_free_lst(&b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	int		flag;
	int		err;
	char	*cmd;

	err = 0;
	if (--argc > 0)
	{
		argv++;
		flag = ft_arg_one(&argc, &argv, &err);
		err = 0;
		a = ft_stack_creation(argc, argv, &err);
		if (!a)
		{
			if (flag)
				ft_free_tab(argv);
			exit(0);
		}
		ft_exec_and_check(&cmd, &a);
		if (flag)
			ft_free_tab(argv);
	}
}
