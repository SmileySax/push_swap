/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:55:37 by keaton            #+#    #+#             */
/*   Updated: 2022/07/22 19:31:58 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (NULL);
}

void	ft_free_and_exit(char ***argv, int flag)
{
	if (flag)
		ft_free_tab(*argv);
	write(2, "Error\n", 6);
	exit(0);
}

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

int	main(int argc, char **argv)
{
	t_list	*a;
	int		flag;
	int		err;

	err = 0;
	if (--argc > 0)
	{
		argv++;
		flag = ft_arg_one(&argc, &argv, &err);
		err = 0;
		a = ft_stack_creation(argc, argv, &err);
		if (!a)
			ft_free_and_exit(&argv, flag);
		if (ft_is_sort(a))
		{
			ft_free_lst(&a);
			ft_free_and_exit(&argv, flag);
			return (0);
		}
		ft_process(&a, argc);
		ft_free_lst(&a);
		if (flag)
			ft_free_tab(argv);
	}
	return (0);
}
