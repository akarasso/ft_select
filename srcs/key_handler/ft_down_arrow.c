#include "ft_select.h"

int		ft_down_arrow(unsigned char *b, t_select *select)
{
	uint	cols;

	if (b[0] == 27 && b[1] == 91 && b[2] == 66 && !b[3])
	{
		cols = select->win.cols;
		while (cols)
		{
			if (select->ptr_elem->next)
				select->ptr_elem = select->ptr_elem->next;
			else
				select->ptr_elem = select->ptr_options->first;
			cols--;
		}
		return (1);
	}
	return (0);
}
