#include "ft_select.h"

void	calc_cols(t_select *select)
{
	t_opt	*opt;

	opt = select->ptr_opt;
	select->win.cols = select->win.width / opt->padding;
	if (!select->win.cols)
		select->win.cols++;
}

int		ft_display_args_value(t_select *select, t_opt *opt, t_file *file, size_t cursor)
{
	size_t	padding;

	if (file->mode & HIDE)
	{
		ft_putstr(RESET);
		return (0);
	}
	padding = file->namelen;
	if (file->mode & SELECT)
		ft_putstr(REVCOLOR);
	ft_putstr(file->color);
	ft_putstr(file->name);
	ft_putstr(RESET);
	while (padding < opt->padding && (cursor + padding) < select->win.width)
	{
		ft_putchar(' ');
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
			ft_putstr(UNDERLINED);
		if (ft_display_args_value(select, opt, file->data, cursor))
		{
			n++;
			if (!(n % select->win.cols))
			{
				cursor = 0;
				ft_putchar('\n');
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
		return ft_display_help(select);
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
