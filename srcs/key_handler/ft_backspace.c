#include "ft_select.h"

int		ft_backspace(unsigned char *b, t_select *select)
{
	t_dlst_elem *futur;

	if ((b[0] == 127 && b[1] == 0)
		|| (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126 && !b[4]))
	{
		if (!select->ptr_elem->next)
		{
			if (select->ptr_elem == select->ptr_options->first)
				futur = 0;
			else
				futur = select->ptr_options->first;
		}
		else
			futur = select->ptr_elem->next;
		ft_dlst_delelem(select->ptr_options, &select->ptr_elem, ft_free_opt);
		select->ptr_elem = futur;
		return (2);
	}
	return (0);
}
