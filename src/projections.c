/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:52:00 by sboez             #+#    #+#             */
/*   Updated: 2017/09/06 20:37:25 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_isometric_proj(t_env *e)
{
	int		i;
	int		x;
	int		y;
	int		z;

	i = 0;
	while (i < e->nb_points)
	{
		x = e->x[i];
		y = e->y[i];
		z = e->z[i];
		e->nx[i] = x * e->scale_h;
		e->ny[i] = y * e->scale_h;
		e->nz[i] = z * (e->scale_h / 6) * -1;
		x = e->origin_x + (e->cte1 * e->nx[i] - e->cte2 * e->ny[i]);
		y = e->origin_y + (e->nz[i] + (e->cte1 / 2)
			* e->nx[i] + (e->cte2 / 2) * e->ny[i]);
		(y >= WIN_Y) ? y = WIN_Y - 1 : y == WIN_Y;
		(x >= WIN_X) ? x = WIN_X - 1 : x == WIN_X;
		e->nx[i] = x;
		e->ny[i] = y;
		(e->nz[i] > e->height_min) ? e->height_min = e->nz[i] : e->height_min;
		(e->nz[i] < e->height_max) ? e->height_max = e->nz[i] : e->height_max;
		i++;
	}
}

void	ft_parallel_proj(t_env *e)
{
	int		i;
	int		x;
	int		y;
	int		z;

	i = 0;
	while (i < e->nb_points)
	{
		x = e->x[i];
		y = e->y[i];
		z = e->z[i];
		e->nx[i] = x * e->scale_h;
		e->ny[i] = y * e->scale_h;
		e->nz[i] = z * (e->scale_h / 6) * -1;
		x = e->origin_x + e->nx[i] + e->cte1 * e->nz[i];
		y = e->origin_y + e->ny[i] + (e->cte1 / 2) * e->nz[i];
		(y >= WIN_Y) ? y = WIN_Y - 1 : y == WIN_Y;
		(x >= WIN_X) ? x = WIN_X - 1 : x == WIN_X;
		e->nx[i] = x;
		e->ny[i] = y;
		(e->nz[i] > e->height_min) ? e->height_min = e->nz[i] : e->height_min;
		(e->nz[i] < e->height_max) ? e->height_max = e->nz[i] : e->height_max;
		i++;
	}
}

void	ft_init_colors(t_env *e)
{
	e->r[0] = 0x55;
	e->g[0] = 0x55;
	e->b[0] = 0x55;
	e->r[1] = 0x99;
	e->g[1] = 0x00;
	e->b[1] = 0xFF;
	e->r[2] = 0x00;
	e->g[2] = 0xCC;
	e->b[2] = 0xFF;
}

void	ft_init_e(t_env *e)
{
	e->height_min = 0;
	e->height_max = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "my fdf");
	e->cte1 = 0.7;
	e->cte2 = 0.9;
	e->origin_x = WIN_X / 2;
	e->origin_y = WIN_Y / 3;
	e->scale_h = 20;
}

void	ft_reset(t_env *e)
{
	e->cte1 = 0.7;
	e->cte2 = 0.9;
	e->origin_x = WIN_X / 2;
	e->origin_y = WIN_Y / 3;
	e->scale_h = 20;
	ft_init_colors(e);
	ft_draw_points_image(e);
	ft_instructions(e);
	ft_isometric_proj(e);
}
