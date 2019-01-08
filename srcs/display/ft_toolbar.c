#include "ft_select.h"

void	ft_display_count_selection(t_select *select)
{
	int		lenCount;
	char	*gotoCmd;

	lenCount = ft_nbr_len(select->nselect);
	gotoCmd = tgoto(tgetstr("cm", 0x0), select->win.width - lenCount - 20 - 1, select->win.height - 1);
	tputs(gotoCmd, STDOUT_FILENO, ft_putint);
	ft_putstr("Nombre de selection:");
	ft_putnbr(select->nselect);
	ft_putstr(" ");
}

void	ft_fill_line(t_select *select, uint curr)
{
	while (curr < select->win.width)
	{
		ft_putstr(" ");
		curr++;
	}
}

void	ft_display_search(t_select *select)
{
	uint curr;

	if (select->search_mode)
	{
		ft_putstr("Recherche:");
		curr = 10;
		if (select->search)
		{
			ft_putstr(select->search);
			curr += ft_strlen(select->search);
		}
	}
	else
	{
		ft_putstr("Mode selection");
		curr = 14;
	}
	ft_fill_line(select, curr);
}

void		ft_toolbar(t_select *select)
{
	char *gotoCmd;

	gotoCmd = tgoto(tgetstr("cm", 0x0), 0, select->win.height - 1);
	tputs(gotoCmd, STDOUT_FILENO, ft_putint);
	ft_putstr(REVCOLOR);
	ft_display_search(select);
	ft_display_count_selection(select);
	ft_putstr(RESET);
}
