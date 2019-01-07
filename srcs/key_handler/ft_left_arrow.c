#include "ft_select.h"

int		ft_left_arrow(unsigned char *b, t_select *select)
{
	t_opt	*opt;

	if (b[0] == 27 && b[1] == 91 && b[2] == 68 && !b[3])
	{
		opt = select->ptr_elem->data;
		if (opt)
		{
			if (select->ptr_elem->prev)
				select->ptr_elem = select->ptr_elem->prev;
			else
				select->ptr_elem = select->ptr_options->last;
			opt = select->ptr_elem->data;
		}
		return (1);
	}
	return (0);
}
