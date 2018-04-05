/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:07:20 by sboez             #+#    #+#             */
/*   Updated: 2016/11/22 11:07:44 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lstnxt;

	tmp = *alst;
	while (tmp)
	{
		lstnxt = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = lstnxt;
	}
	*alst = NULL;
}
