/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:41 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:33:42 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_space(unsigned char *b, t_select *select)
{
	t_dlst_elem	*next;
	t_file		*file;

	if (b[0] == 32 && b[1] == 0 && select->ptr_elem && select->ptr_elem->data
		&& select->mode == SELECT_MOD)
	{
		file = select->ptr_elem->data;
		if (select->ptr_opt->parent && (!ft_strcmp(file->name, "..")
			|| (file->mode & HIDE) || (file->mode & LOCK)))
			return (1);
		if (file->mode & SELECT)
		{
			select->nselect--;
			file->mode &= (0xFF ^ SELECT);
		}
		else
		{
			select->nselect++;
			file->mode |= SELECT;
		}
		next = ft_select_next(select->ptr_opt->files, select->ptr_elem, 1);
		select->ptr_elem = next;
		return (1);
	}
	return (0);
}
