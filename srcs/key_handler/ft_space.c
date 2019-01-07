#include "ft_select.h"

int		ft_space(unsigned char *b, t_select *select)
{
	t_opt *opt;

	if (b[0] == 32 && b[1] == 0)
	{
		if ((opt = select->ptr_elem->data))
		{
			opt->state = opt->state == SELECT ? UNSELECT : SELECT;
			if (select->ptr_elem->next)
				select->ptr_elem = select->ptr_elem->next;
			else
				select->ptr_elem = select->ptr_options->first;
			opt = select->ptr_elem->data;
		}
		return (1);
	}
	return (0);
}
