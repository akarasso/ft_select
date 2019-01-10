#include "ft_select.h"

/*
**	Ctrl + R
*/

int			show_touch_is_case_event(unsigned char *buff)
{
	if (buff[0] != 27)
		return (0);
	if (buff[1] == 91 || buff[1] == 79)
		return (1);
	return (0);
}

int			ft_research(unsigned char *b, t_select *select)
{
	if (!(b[0] == 10 && b[1] == 0) && select->mode == SEARCH_MOD)
	{
		if (!show_touch_is_case_event(b))
			select->search = ft_strjoinfree(select->search, (char*)b, LEFT);
		return (1);
	}
	if (b[0] == 18 && b[1] == 0 && select->mode == SELECT_MOD)
	{
		select->mode = SEARCH_MOD;
		return (1);
	}
	return (0);
}
