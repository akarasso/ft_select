#include "ft_select.h"

/*
**	Ctrl + R
*/

int		ft_research(unsigned char *b, t_select *select)
{
	(void)select;
	if (b[0] == 18 && b[1] == 0)
	{
		return (1);
	}
	return (0);
}
