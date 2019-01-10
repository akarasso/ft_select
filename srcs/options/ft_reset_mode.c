#include "ft_select.h"

void	ft_reset_mode(t_dlst *files, char mode)
{
	t_dlst_elem		*elem;
	t_file			*file;

	if (!files)
		return ;
	elem = files->first;
	while (elem)
	{
		file = elem->data;
		file->mode &= mode;
		elem = elem->next;
	}
}
