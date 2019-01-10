/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:03 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:34:17 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_down_arrow(unsigned char *b, t_select *select)
{
	t_dlst_elem *next;

	if (b[0] == 27 && b[1] == 91 && b[2] == 66 && !b[3]
		&& select->mode == SELECT_MOD)
	{
		next = ft_select_next(select->ptr_opt->files,
			select->ptr_elem, select->win.cols);
		select->ptr_elem = next;
		return (1);
	}
	return (0);
}
