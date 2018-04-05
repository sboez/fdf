/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:51:25 by sboez             #+#    #+#             */
/*   Updated: 2017/09/06 20:33:14 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_instructions(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF, "Isometric : i");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "Parallel : p");
	mlx_string_put(e->mlx, e->win, 10, 55, 0xFFFFFF, "Move : <- | -> ");
	mlx_string_put(e->mlx, e->win, 10, 80, 0xFFFFFF, "Zoom : + -");
	mlx_string_put(e->mlx, e->win, 10, 105, 0xFFFFFF, "Colors : r g b");
	mlx_string_put(e->mlx, e->win, 10, 130, 0xFFFFFF, "Size : q w a s");
	mlx_string_put(e->mlx, e->win, 10, 150, 0xFFFFFF, "Reset : space");
}

int		ft_move_parallel(int keycode, t_env *e)
{
	e->proj = 2;
	(keycode == UP) ? e->origin_y -= 5 : e->origin_y;
	(keycode == DOWN) ? e->origin_y += 5 : e->origin_y;
	(keycode == RIGHT) ? e->origin_x += 5 : e->origin_x;
	(keycode == LEFT) ? e->origin_x -= 5 : e->origin_x;
	(keycode == ZOOM) ? e->scale_h += 1 : e->scale_h;
	(keycode == DEZOOM && e->scale_h > 0) ? e->scale_h -= 1 : e->scale_h;
	(keycode == CTE1MORE) ? e->cte1 += 0.1 : e->cte1;
	(keycode == CTE2MORE) ? e->cte2 += 0.1 : e->cte2;
	(keycode == CTE1LESS) ? e->cte1 -= 0.1 : e->cte1;
	(keycode == CTE2LESS) ? e->cte2 -= 0.1 : e->cte2;
	if (keycode == RESET)
		ft_reset(e);
	ft_parallel_proj(e);
	ft_draw_points_image(e);
	if (keycode == EXIT)
		exit(0);
	return (0);
}

int		ft_move_isometric(int keycode, t_env *e)
{
	e->proj = 1;
	(keycode == UP) ? e->origin_y -= 5 : e->origin_y;
	(keycode == DOWN) ? e->origin_y += 5 : e->origin_y;
	(keycode == RIGHT) ? e->origin_x += 5 : e->origin_x;
	(keycode == LEFT) ? e->origin_x -= 5 : e->origin_x;
	(keycode == ZOOM) ? e->scale_h += 1 : e->scale_h;
	(keycode == DEZOOM && e->scale_h > 0) ? e->scale_h -= 1 : e->scale_h;
	(keycode == CTE1MORE) ? e->cte1 += 0.1 : e->cte1;
	(keycode == CTE2MORE) ? e->cte2 += 0.1 : e->cte2;
	(keycode == CTE1LESS && e->cte1 > 0.1) ? e->cte1 -= 0.1 : e->cte1;
	(keycode == CTE2LESS && e->cte2 > 0.1) ? e->cte2 -= 0.1 : e->cte2;
	if (keycode == RESET)
		ft_reset(e);
	ft_isometric_proj(e);
	ft_draw_points_image(e);
	if (keycode == EXIT)
		exit(0);
	return (0);
}

int		ft_change_colors(int keycode, t_env *e)
{
	if (keycode == RGB_R)
	{
		e->r[0] += 0x11;
		e->r[1] += 0x11;
		e->r[2] += 0x11;
	}
	if (keycode == RGB_G)
	{
		e->g[0] += 0x11;
		e->g[1] += 0x11;
		e->g[2] += 0x11;
	}
	if (keycode == RGB_B)
	{
		e->b[0] += 0x11;
		e->b[1] += 0x11;
		e->b[2] += 0x11;
	}
	return (0);
}

int		ft_choose_projection(int keycode, t_env *e)
{
	if (keycode == ISOMETRIC)
		e->proj = 1;
	if (keycode == PARALLEL)
		e->proj = 2;
	ft_change_colors(keycode, e);
	if (e->proj == 1)
		ft_move_isometric(keycode, e);
	if (e->proj == 2)
		ft_move_parallel(keycode, e);
	if (keycode == EXIT)
		exit(0);
	return (0);
}
