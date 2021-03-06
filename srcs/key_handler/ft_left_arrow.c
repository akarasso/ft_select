/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:19 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:33:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_left_arrow(unsigned char *b, t_select *select)
{
	t_dlst_elem	*prev;

	if (b[0] == 27 && b[1] == 91 && b[2] == 68 && !b[3]
		&& select->mode == SELECT_MOD)
	{
		prev = ft_select_prev(select->ptr_opt->files, select->ptr_elem, 1);
		select->ptr_elem = prev;
		return (1);
	}
	return (0);
}
