#include "ft_select.h"

void	calc_cols(t_select *select)
{
	if ((select->win.padding + 3) * select->ptr_options->len < select->win.width)
		select->win.cols = select->ptr_options->len;
	else
	{
		select->win.cols = select->win.width / (select->win.padding + 3);
		if (!select->win.cols)
			select->win.cols = 1;
	}
}

void	ft_display_args_value(t_select *select, t_opt *opt)
{
	uint	padding;

	padding = opt->namelen;
	if (opt->state == SELECT)
		ft_putstr(REVCOLOR);
	ft_putstr(opt->name);
	ft_putstr(RESET);
	while (padding < select->win.padding)
	{
		ft_putchar(' ');
		padding++;
	}
}

void	ft_display_args(t_select *select, t_dlst_elem *elem)
{
	uint	n;

	while (elem)
	{
		n = 0;
		if (elem == select->ptr_elem)
			ft_putstr(UNDERLINED);
		ft_display_args_value(select, elem->data);
		elem = elem->next;
		n++;
		if (n == select->win.cols)
			ft_putchar('\n');
	}
}

void	ft_display(t_select *select)
{
	tputs(tgetstr("cl", NULL), 1, ft_putint);
	calc_cols(select);
	select->win.rows = select->ptr_options->len / select->win.cols;
	if (select->ptr_options->len % select->win.cols)
		select->win.rows++;
	if (select->win.rows > select->win.height)
		ft_putstr("...");
	else
	{
		ft_display_args(select, select->ptr_options->first);
		ft_toolbar(select);
	}
}
