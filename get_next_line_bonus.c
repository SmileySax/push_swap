/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:22:41 by keaton            #+#    #+#             */
/*   Updated: 2022/03/13 13:41:15 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_freelinefunc(char *where, char *what, char i)
{
	char	*prev;

	prev = where;
	if (i == 'j')
		where = ft_strjoin((const char *)where, (const char *)what);
	if (i == 'd')
		where = ft_strdup((const char *)what);
	if (i == 'f')
		where = NULL;
	if (prev)
		free(prev);
	prev = NULL;
	if (where == NULL)
		return (NULL);
	return (where);
}

char	*ft_safe2safe(char *safe, int *flag, char **line)
{
	char	*n_ptr;
	char	res;

	if (*safe)
	{
		*flag = 1;
		n_ptr = ft_strchr(safe, '\n');
		if (n_ptr)
		{
			res = *(++n_ptr);
			*n_ptr = '\0';
			*line = ft_freelinefunc(*line, safe, 'd');
			*(n_ptr) = res;
			safe = ft_strcpy(safe, n_ptr);
		}
		else
		{
			*line = ft_freelinefunc(*line, safe, 'd');
			free(safe);
			safe = NULL;
		}
	}
	else
		safe = ft_freelinefunc(safe, safe, 'f');
	return (safe);
}

char	*ft_line2safe2(char **safe, char **line, char **buff)
{
	char	*n_ptr;

	n_ptr = ft_strchr(*buff, '\n');
	if (n_ptr)
	{
		*safe = ft_freelinefunc(*safe, ++n_ptr, 'd');
		if (*safe == NULL)
		{
			free (*line);
			*line = NULL;
			return (NULL);
		}
		*n_ptr = '\0';
	}
	*line = ft_freelinefunc(*line, *buff, 'j');
	return (*safe);
}

char	*ft_line2safe(char *safe, int *flag, char **line, int *n)
{
	char	*buff;
	int		fd;

	fd = *n;
	buff = (char *)malloc(sizeof(char) * (6 + 1));
	if (buff == NULL)
	{
		free (*line);
		*line = NULL;
		return (NULL);
	}
	buff[6] = '\0';
	while (!safe)
	{
		*n = read(fd, buff, 6);
		if (*n <= 0)
			break ;
		*flag = 1;
		*(buff + *n) = '\0';
		safe = ft_line2safe2(&safe, line, &buff);
	}
	free(buff);
	return (safe);
}

char	*get_next_line(int fd)
{
	static char	*safe;
	char		*line;
	int			n;
	int			flag;

	if (fd < 0)
		return (NULL);
	n = fd;
	flag = 0;
	line = ft_strdup("");
	if (safe)
		safe = ft_safe2safe(safe, &flag, &line);
	if (line == NULL)
		return (NULL);
	if (!safe)
		safe = ft_line2safe(safe, &flag, &line, &n);
	if (line == NULL)
		return (NULL);
	if (flag != 0)
	{
		return (line);
	}
	free(line);
	return (NULL);
}
