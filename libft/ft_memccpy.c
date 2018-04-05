/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:03:01 by sboez             #+#    #+#             */
/*   Updated: 2016/11/09 15:04:26 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char*)dst)[i] = ((unsigned char*)src)[i])
			== (unsigned char)c)
			return (((unsigned char*)dst) + i + 1);
		i++;
	}
	return (NULL);
}
