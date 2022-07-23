/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:22:59 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 17:36:52 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

#include<stdio.h>//----------

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
}	t_list;

char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*get_next_line(int fd);
t_list	*ft_stack_creation(int argc, char **argv, int *err);
t_list	*ft_create_elem(int num);
t_list	*ft_lstadd_front(t_list *lst, int num);
void	ft_putchar_fd(char c, int fd);
int		ft_numreader(char *arg, int *err, int p);
int		ft_err_atoi(char *arg, int *err);
int		ft_is_uniq(unsigned int *tab, int i, int *err);
int		ft_is_sort(t_list *begin_list);
int		ft_resort_tab(unsigned int **tab, int tab2[10], int l, int p);
int		ft_sort_tab(unsigned int **tab, int l);
int		ft_sort_n_check(t_list *begin_list, int *err, int argc);
void	ft_process(t_list **a, int argc);
void	ft_process_3(t_list **a, int argc);
void	ft_process_6(t_list **a, t_list **b, int l);
void	ft_sort(t_list **a, t_list **b, int l);
int		ft_find_max_elem(t_list *list, int l);
int		ft_find_min_elem(t_list *list);
void	ft_presort(t_list **a, t_list **b, int argc);
void	swap(t_list **begin_list);
void	ft_push(t_list **from, t_list **to);
void	ft_rotate(t_list **begin_list);
void	ft_reverse_rotate(t_list **begin_list);
int		ft_countwords(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_free_tab(char **tab);
int		ft_strlen(const char *str);
void	ft_free_lst(t_list **lst);
void	sa(t_list **begin_list);
void	sb(t_list **begin_list);
void	ss(t_list **begin_list_a, t_list **begin_list_b);
void	pa(t_list **begin_list_a, t_list **begin_list_b);
void	pb(t_list **begin_list_a, t_list **begin_list_b);
void	ra(t_list **begin_list);
void	rb(t_list **begin_list);
void	rr(t_list **begin_list_a, t_list **begin_list_b);
void	rra(t_list **begin_list);
void	rrb(t_list **begin_list);
void	rrr(t_list **a, t_list **b);

#endif
