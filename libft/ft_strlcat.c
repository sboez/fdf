/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:01:04 by sboez             #+#    #+#             */
/*   Updated: 2016/11/07 23:01:13 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_src;
	size_t len_dst;
	size_t i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst)
		return (size + len_src);
	i = 0;
	while (src[i] != '\0' && (len_dst + i + 1) < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
