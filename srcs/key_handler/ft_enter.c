#include "ft_select.h"

void	ft_filter_display(t_select *select)
{
	t_file		*file;
	t_dlst_elem	*elem;

	if (!select->search)
		return ;
	elem = select->ptr_opt->files->first;
	while (elem)
	{
		file = elem->data;
		if ((file->mode & LOCK)
			|| (!(file->mode & LOCK) && ft_strstr(file->name, select->search)))
			file->mode &= (0xFF ^ HIDE);
		else
			file->mode |= HIDE;
		elem = elem->next;
	}
	elem = ft_select_next(select->ptr_opt->files, select->ptr_elem, 1);
	if (elem == select->ptr_elem)
		elem = 0;
	select->ptr_elem = elem;
}

int		ft_enter(unsigned char *b, t_select *select)
{
	if (b[0] == 10 && b[1] == 0 && select->mode == SELECT_MOD)
	{
		select->stop = 1;
		return (1);
	}
	if (b[0] == 10 && b[1] == 0 && select->mode == SEARCH_MOD)
	{
		ft_filter_display(select);
		select->mode = SELECT_MOD;
		return (1);
	}
	return (0);
}
