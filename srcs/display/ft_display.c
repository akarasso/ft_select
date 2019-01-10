/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:28:00 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 15:11:04 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	calc_cols(t_select *select)
{
	t_opt	*opt;

	opt = select->ptr_opt;
	select->win.cols = select->win.width / opt->padding;
	if (!select->win.cols)
		select->win.cols++;
}

int		ft_display_args_value(t_select *select,
		t_opt *opt, t_file *file, size_t cursor)
{
	size_t	padding;

	if (file->mode & HIDE)
	{
		ft_putstr_fd(RESET, STDERR_FILENO);
		return (0);
	}
	padding = file->namelen;
	if (file->mode & SELECT)
		ft_putstr_fd(REVCOLOR, STDERR_FILENO);
	ft_putstr_fd(file->color, STDERR_FILENO);
	ft_putstr_fd(file->name, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	while (padding < opt->padding && (cursor + padding) < select->win.width)
	{
		ft_putchar_fd(' ', STDERR_FILENO);
		padding++;
	}
	return (1);
}

void	ft_display_args(t_select *select, t_opt *opt, t_dlst *files)
{
	size_t		n;
	size_t		cursor;
	t_dlst_elem	*file;

	file = files->first;
	n = 0;
	cursor = 0;
	while (file)
	{
		if (file == select->ptr_elem)
			ft_putstr_fd(UNDERLINED, STDERR_FILENO);
		if (ft_display_args_value(select, opt, file->data, cursor))
		{
			n++;
			if (!(n % select->win.cols))
			{
				cursor = 0;
				ft_putchar_fd('\n', STDERR_FILENO);
			}
		}
		file = file->next;
	}
}

void	ft_display(t_select *select)
{
	int	row_toolbar;

	tputs(tgetstr("cl", 0x0), 1, ft_putint);
	if (select->mode == HELP_MOD)
		return (ft_display_help(select));
	calc_cols(select);
	select->win.rows = select->ptr_opt->files->len / select->win.cols;
	if (select->ptr_opt->files->len % select->win.cols)
		select->win.rows++;
	row_toolbar = ft_toolbar_len(select);
	if (select->win.rows > select->win.height - row_toolbar)
		ft_putstr("...");
	else
	{
		ft_display_args(select, select->ptr_opt, select->ptr_opt->files);
		ft_toolbar(select);
	}
}
