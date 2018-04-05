/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:51:47 by sboez             #+#    #+#             */
/*   Updated: 2017/09/06 22:38:26 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fill_pixel(void *img, unsigned long color, t_env *e)
{
	int		i;

	e->data = mlx_get_data_addr(img, &e->bpp, &e->sizeline, &e->endian);
	i = e->x0 * 4 + e->y0 * e->sizeline;
	if (e->x0 >= 0 && e->y0 >= 0 && e->x0 <= WIN_X && e->y0 <= WIN_Y)
	{
		e->data[i] = color % 256;
		color /= 256;
		e->data[i + 1] = color % 256;
		color /= 256;
		e->data[i + 2] = color % 256;
		color /= 256;
		e->data[i + 3] = 0;
		color /= 256;
	}
}

void	ft_draw_lines(t_env *e)
{
	t_draw	s;

	s.dx = abs(e->x1 - e->x0);
	s.dy = abs(e->y1 - e->y0);
	s.sx = e->x0 < e->x1 ? 1 : -1;
	s.sy = e->y0 < e->y1 ? 1 : -1;
	e->err = (s.dx > s.dy ? s.dx : -s.dy) / 2;
	while (e->x0)
	{
		ft_fill_pixel(e->img, e->color, e);
		if (e->x0 == e->x1 && e->y0 == e->y1)
			break ;
		e->e2 = e->err;
		if (e->e2 > -s.dx)
		{
			e->err -= s.dy;
			e->x0 += s.sx;
		}
		if (e->e2 < s.dy)
		{
			e->err += s.dx;
			e->y0 += s.sy;
		}
	}
}

void	ft_tool_draw(t_env *e, int i)
{
	if (e->nx[i + 1] >= e->nx[i])
	{
		e->x0 = e->nx[i];
		e->y0 = e->ny[i];
		e->x1 = e->nx[i + 1];
		e->y1 = e->ny[i + 1];
		ft_draw_lines(e);
	}
	if (i <= e->max_draw)
	{
		e->x0 = e->nx[i];
		e->y0 = e->ny[i];
		e->x1 = e->nx[i + e->max_col];
		e->y1 = e->ny[i + e->max_col];
		ft_draw_lines(e);
	}
}

void	ft_draw_points_image(t_env *e)
{
	int		i;

	i = 0;
	e->max_col = e->nb_columns;
	e->max_draw = e->nb_points - e->nb_columns - 1;
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	while (i < e->nb_points)
	{
		if (e->nz[i] > 0)
			e->color = (e->r[1] << 16) | (e->g[1] << 8) | e->b[1];
		if (e->nz[i] < 0 && e->nz[i])
			e->color = (e->r[2] << 16) | (e->g[2] << 8) | e->b[2];
		if (e->nz[i] == 0)
			e->color = (e->r[0] << 16) | (e->g[0] << 8) | e->b[0];
		ft_tool_draw(e, i);
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_instructions(e);
	mlx_destroy_image(e->mlx, e->img);
}
