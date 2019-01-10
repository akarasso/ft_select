/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_prev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:56:34 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/08 17:20:39 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlst_elem	*ft_select_prev(t_dlst *container, t_dlst_elem *elem, size_t n)
{
	t_dlst_elem		*from;
	t_file			*file;

	if (!elem)
		elem = container->first;
	from = elem;
	elem = elem->prev ? elem->prev : container->last;
	while (elem && elem != from)
	{
		file = elem->data;
		if (!(file->mode & HIDE))
		{
			n--;
			if (!n)
				return (elem);
		}
		elem = elem->prev ? elem->prev : container->last;
	}
	return (elem);
}
