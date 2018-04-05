/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:17:10 by sboez             #+#    #+#             */
/*   Updated: 2017/01/16 15:21:22 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 999
# define GNL_ERROR -1
# define GNL_END 0
# define GNL_OK 1

int		ft_realloc(char **rest);
char	*ft_fill_line(char **line, char **str, char *rest);
int		ft_free_rest(char **rest, char **str);
int		get_next_line(const int fd, char **line);

#endif
