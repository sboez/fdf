/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:28:20 by sboez             #+#    #+#             */
/*   Updated: 2017/09/06 20:35:22 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error1(int n, t_env *e, char **argv)
{
	e->x = (int*)malloc(n * sizeof(int));
	e->y = (int*)malloc(n * sizeof(int));
	e->z = (int*)malloc(n * sizeof(int));
	e->nx = (int*)malloc(n * sizeof(int));
	e->ny = (int*)malloc(n * sizeof(int));
	e->nz = (int*)malloc(n * sizeof(int));
	e->r = (unsigned long*)malloc(3 * sizeof(unsigned long));
	e->g = (unsigned long*)malloc(3 * sizeof(unsigned long));
	e->b = (unsigned long*)malloc(3 * sizeof(unsigned long));
	if (e->nb_points == 0)
	{
		ft_putstr("Error. Empty file\n");
		exit(1);
	}
}

void	ft_error2(char **argv, t_env *e)
{
	if (!(argv[1]))
	{
		ft_putstr("Error. No file selected\n");
		exit(1);
	}
	if (argv[2])
	{
		ft_putstr("Error. Too many parameters\n");
		exit(1);
	}
}

int		ft_red_cross(void)
{
	exit(0);
}

int		main(int argc, char **argv)
{
	int		n;
	int		keycode;
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
	{
		ft_putstr("Erreur Malloc -> t_env");
		exit(1);
	}
	ft_error2(argv, e);
	n = ft_load_file(argv[1], e);
	ft_error1(n, e, argv);
	ft_init_colors(e);
	ft_init_e(e);
	ft_read_file(argv[1], e);
	ft_isometric_proj(e);
	e->proj = 1;
	ft_draw_points_image(e);
	ft_instructions(e);
	mlx_hook(e->win, 2, 3, ft_choose_projection, e);
	mlx_hook(e->win, 17, 0, ft_red_cross, 0);
	mlx_loop(e->mlx);
	return (0);
}
