#include "ft_select.h"

int		ft_escape(unsigned char *b, t_select *select)
{
	(void)select;
	if (b[0] == 27 && b[1] == 0)
	{
		return (1);
	}
	return (0);
}
