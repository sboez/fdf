/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:39:51 by sboez             #+#    #+#             */
/*   Updated: 2017/07/26 15:15:31 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "includes/libft.h"
#include "get_next_line.h"

int		ft_realloc(char **rest)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*rest))))
		return (0);
	tmp = ft_strcpy(tmp, *rest);
	ft_memdel((void **)rest);
	if (!(*rest = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	*rest = ft_strcpy(*rest, tmp);
	ft_memdel((void **)&tmp);
	tmp = NULL;
	return (1);
}

char	*ft_fill_line(char **line, char **str, char *rest)
{
	int		i;

	i = 0;
	*line = ft_strnew(ft_strlen(*str));
	while ((*str)[i] && (*str)[i] != '\n')
	{
		(*line)[i] = (*str)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*str)[i] == '\n')
	{
		i++;
		ft_memdel((void **)&rest);
		if (!(rest = ft_strdup(*str + i)))
			return (NULL);
	}
	else
	{
		if (!(rest = ft_strdup(*str + i)))
			return (NULL);
	}
	return (rest);
}

int		ft_free_rest(char **rest, char **str)
{
	ft_memdel((void **)rest);
	ft_memdel((void **)str);
	return (GNL_END);
}

int		get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*str;

	(rest == NULL) ? rest = ft_strnew(1) : 0;
	if (!(str = ft_strdup(rest)) || (fd < 0))
		return (GNL_ERROR);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(ft_realloc(&str)))
			return (GNL_ERROR);
		str = ft_strcat(str, buff);
		if (ft_memchr(buff, '\n', BUFF_SIZE))
			break ;
	}
	if (ret < 0)
		return (GNL_ERROR);
	rest = ft_fill_line(line, &str, rest);
	if (ret == 0 && ft_strcmp(str, rest) == 0)
		return (ft_free_rest(&rest, &str));
	ft_memdel((void **)&str);
	return (GNL_OK);
}
