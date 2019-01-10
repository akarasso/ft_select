/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:24:40 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:25:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_print_file(t_dlst_elem *elem)
{
	t_file		*file;
	t_select	*select;

	file = elem->data;
	select = ft_get_select();
	if (file)
	{
		if (file->mode & SELECT)
		{
			if (select->printed++)
				ft_putstr(" ");
			if (file->path)
			{
				ft_putstr(file->path);
				ft_putstr("/");
			}
			ft_putstr(file->name);
		}
		if (file->subopt)
			ft_print_opt(file->subopt);
	}
}

void	ft_print_opt(t_opt *opt)
{
	if (opt)
		ft_dlst_iter(opt->files, ft_print_file);
}

void	ft_print_args(t_select *select)
{
	if (select->opt)
		ft_print_opt(select->opt);
}
