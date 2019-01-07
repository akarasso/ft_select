#include "ft_select.h"

int		ft_goto(unsigned char *b, t_select *select)
{
	(void)select;
	if (b[0] == 103 && b[1] == 0)
	{
		return (1);
	}
	return (0);
}
