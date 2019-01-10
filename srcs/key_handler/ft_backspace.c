/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:32:58 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:34:33 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	free_opt(void *data)
{
	t_file	*file;

	file = data;
	if (file)
	{
		ft_strdel(&file->name);
		ft_strdel(&file->path);
		if (file->subopt)
			ft_free_opt(file->subopt);
		free(file);
	}
}

static void	ft_delete_option(t_select *select)
{
	t_dlst_elem		*futur;
	t_file			*file;

	if (!select->ptr_elem || !select->ptr_elem->data)
		return ;
	file = select->ptr_elem->data;
	if (file->mode & LOCK)
		return ;
	futur = ft_select_next(select->ptr_opt->files, select->ptr_elem, 1);
	if (futur == select->ptr_elem)
		futur = 0;
	ft_dlst_delelem(select->ptr_opt->files, &select->ptr_elem, free_opt);
	select->ptr_elem = futur;
	if (select->ptr_opt->files->len == 0)
	{
		ft_free_args(select);
		select->stop = 1;
	}
}

int			ft_backspace(unsigned char *b, t_select *select)
{
	char		*ptr;

	if ((b[0] == 127 && b[1] == 0)
		|| (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126 && !b[4]))
	{
		if (select->mode == SEARCH_MOD && (ptr = ft_strlastchr(select->search)))
			*ptr = 0;
		else if (select->mode == SELECT_MOD)
			ft_delete_option(select);
		return (2);
	}
	return (0);
}
