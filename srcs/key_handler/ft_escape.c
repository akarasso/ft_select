#include "ft_select.h"

int		ft_escape(unsigned char *b, t_select *select)
{
	if (b[0] == 27 && b[1] == 0 && select->mode == HELP_MOD)
	{
		select->mode = SELECT_MOD;
		return (1);
	}
	if (b[0] == 27 && b[1] == 0 && select->mode == SELECT_MOD)
	{
		ft_free_args(select);
		select->stop = 1;
		return (1);
	}
	return (0);
}
