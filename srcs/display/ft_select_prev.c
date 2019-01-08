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

t_dlst_elem	*ft_select_prev(t_dlst *container, t_dlst_elem *elem, int n)
{
	t_dlst_elem		*from;
	t_opt			*opt;

	from = elem;
	elem = elem->prev ? elem->prev : container->last;
	while (elem != from)
	{
		opt = elem->data;
		if (opt->visibility == SHOW)
		{
			n--;
			if (!n)
				break;
		}
		elem = elem->prev ? elem->prev : container->last;
	}
	return (elem);
}
