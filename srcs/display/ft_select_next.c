/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:56:46 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/08 17:21:57 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlst_elem	*ft_select_next(t_dlst *container, t_dlst_elem *elem, size_t n)
{
	t_dlst_elem		*from;
	t_file			*file;

	if (!elem)
		elem = container->first;
	from = elem;
	elem = elem->next ? elem->next : container->first;
	while (elem && elem != from)
	{
		file = elem->data;
		if (!(file->mode & HIDE))
		{
			n--;
			if (!n)
				return (elem);
		}
		elem = elem->next ? elem->next : container->first;
	}
	return (elem);
}
