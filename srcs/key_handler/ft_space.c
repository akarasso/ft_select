#include "ft_select.h"

int		ft_space(unsigned char *b, t_select *select)
{
	t_dlst_elem	*next;
	t_opt		*opt;

	if (b[0] == 32 && b[1] == 0 && select->ptr_elem && select->ptr_elem->data)
	{
		opt = select->ptr_elem->data;
		if (opt->state == SELECT)
		{
			select->nselect--;
			opt->state = UNSELECT;
		}
		else
		{
			select->nselect++;
			opt->state = SELECT;
		}
		next = ft_select_next(select->ptr_options, select->ptr_elem, 1);
		select->ptr_elem = next;
		return (1);
	}
	return (0);
}
