#include "ft_select.h"

int		ft_right_arrow(unsigned char *b, t_select *select)
{
	t_dlst_elem *next;

	if (b[0] == 27 && b[1] == 91 && b[2] == 67 && !b[3])
	{
		next = ft_select_next(select->ptr_options, select->ptr_elem, 1);
		select->ptr_elem = next;
		return (1);
	}
	return (0);
}
