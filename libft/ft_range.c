/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:47:41 by sboez             #+#    #+#             */
/*   Updated: 2016/11/24 09:48:06 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int start, int end)
{
	int *tab;
	int i;

	if (start >= end)
		return (NULL);
	tab = (int*)malloc(sizeof(*tab) * (end - start));
	i = 0;
	while (start < end)
	{
		tab[i] = start;
		i++;
		start++;
	}
	return (tab);
}
