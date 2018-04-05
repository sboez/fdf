/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 22:20:04 by sboez             #+#    #+#             */
/*   Updated: 2017/09/07 00:09:06 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_X 2200
# define WIN_Y 1200
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM 24
# define DEZOOM 27
# define ISOMETRIC 34
# define PARALLEL 35
# define CTE1MORE 12
# define CTE2MORE 13
# define CTE1LESS 0
# define CTE2LESS 1
# define RGB_R 15
# define RGB_G 5
# define RGB_B 11
# define RESET 49
# define EXIT 53

typedef	struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				*x;
	int				*y;
	int				*z;
	int				*nx;
	int				*ny;
	int				*nz;
	unsigned long	*r;
	unsigned long	*g;
	unsigned long	*b;
	int				nb_points;
	int				nb_lines;
	int				nb_columns;
	int				scale_h;
	int				origin_x;
	int				origin_y;
	double			cte1;
	double			cte2;
	int				height_min;
	int				height_max;
	unsigned long	color;
	int				err;
	int				e2;
	int				proj;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				max_draw;
	int				max_col;
	int				fd;
}					t_env;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
}					t_draw;

int					ft_read_file(char *argv, t_env *e);
int					ft_load_file(char *argv, t_env *e);
void				ft_fill_pixel(void *img, unsigned long color, t_env *e);
void				ft_isometric_proj(t_env *e);
void				ft_parallel_proj(t_env *e);
void				ft_draw_lines(t_env *e);
void				ft_instructions(t_env *e);
void				ft_draw_points_image(t_env *e);
void				ft_reset(t_env *e);
int					ft_move_parallel(int keycode, t_env *e);
int					ft_move_isometric(int keycode, t_env *e);
void				ft_init_colors(t_env *e);
int					ft_change_colors(int keycode, t_env *e);
int					ft_choose_projection(int keycode, t_env *e);
void				ft_error1(int n, t_env *e, char **argv);
void				ft_error2(char **argv, t_env *e);
void				ft_init_e(t_env *e);
void				ft_tool_draw(t_env *e, int i);

#endif
