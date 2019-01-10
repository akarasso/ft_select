#include "ft_select.h"

void	ft_display_count_selection(t_select *select, size_t *curr, int row_toolbar)
{
	int		lenCount;
	char	*gotoCmd;

	lenCount = ft_nbr_len(select->nselect);
	if (row_toolbar == 2)
	{
		ft_fill_line(*curr, select->win.width);
		gotoCmd = tgoto(tgetstr("cm", 0x0), 0, select->win.height - 1);
		tputs(gotoCmd, STDOUT_FILENO, ft_putint);
		(*curr) = 0;
	}
	else
	{
		ft_fill_line((*curr), select->win.width - 20 - lenCount);
		(*curr) = select->win.width - 20 - lenCount;
	}
	ft_putstr("Nombre de selection:");
	ft_putnbr(select->nselect);
	(*curr) += 20 + lenCount;
}

void	ft_display_search_mode(t_select *select, size_t *curr)
{
	size_t		len;
	char		*ptr;

	ft_putstr("Recherche:");
	*curr = 10;
	if (select->search)
	{
		len = ft_strlen(select->search);
		if (10 + len < select->win.width)
		{
			ft_putstr(select->search);
			(*curr) += len;
		}
		else
		{
			ptr = select->search + len - (select->win.width - 13);
			ft_putstr("...");
			ft_putstr(ptr);
			(*curr) += select->win.width;
		}
	}
	else
	{
		ft_putstr("<string>");
		(*curr) += 8;
	}
}

void	ft_display_select_mode(size_t *curr)
{
	ft_putstr("Mode selection");
	(*curr) = 14;
}

void		ft_toolbar(t_select *select)
{
	char	*gotoCmd;
	int		row_toolbar;
	size_t	curr;

	curr = 0;
	row_toolbar = ft_toolbar_len(select);
	gotoCmd = tgoto(tgetstr("cm", 0x0), 0, select->win.height - row_toolbar);
	tputs(gotoCmd, STDOUT_FILENO, ft_putint);
	ft_putstr(REVCOLOR);
	if (select->mode == SEARCH_MOD)
		ft_display_search_mode(select, &curr);
	else
		ft_display_select_mode(&curr);
	ft_display_count_selection(select, &curr, row_toolbar);
	ft_fill_line(curr, select->win.width);
	ft_putstr(RESET);
}
