/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:51:37 by sboez             #+#    #+#             */
/*   Updated: 2017/08/09 16:51:39 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_read_file(char *argv, t_env *e)
{
	char	**tab;
	char	*line;
	int		i;
	int		j;

	i = 0;
	e->nb_points = 0;
	e->fd = open(argv, O_RDONLY);
	while (get_next_line(e->fd, &line) == 1)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[j])
		{
			e->z[e->nb_points] = ft_atoi(tab[j]);
			e->x[e->nb_points] = j;
			e->y[e->nb_points] = i;
			j++;
			e->nb_points++;
		}
		free(line);
		i++;
	}
	close(e->fd);
	return (0);
}

int		ft_load_file(char *argv, t_env *e)
{
	char	**tab;
	char	*line;
	int		i;
	int		j;

	i = 0;
	e->nb_points = 0;
	e->fd = open(argv, O_RDONLY);
	while (get_next_line(e->fd, &line) == 1)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[j])
		{
			j++;
			e->nb_points++;
		}
		free(line);
		i++;
	}
	if (close(e->fd) < 0)
		ft_putstr("Error closing file.");
	e->nb_lines = i - 1;
	e->nb_columns = j;
	return (e->nb_points);
}
