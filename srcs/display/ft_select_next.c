/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:56:46 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/07 18:56:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlst_elem	*ft_select_next(t_dlst *container, t_dlst_elem *elem, int n)
{
	t_dlst_elem		*from;
	t_opt			*opt;

	from = elem;
	elem = elem->next ? elem->next : container->first;
	while (elem != from)
	{
		opt = elem->data;
		if (opt->visibility == SHOW)
			break;
		elem = elem->next ? elem->next : container->first;
	}
	if (elem == from)
		return (0x0);
	return (elem);
}
