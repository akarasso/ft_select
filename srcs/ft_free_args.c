#include "ft_select.h"

void	ft_free_file(t_dlst_elem *elem)
{
	t_file	*file;

	file = elem->data;
	if (file)
	{
		ft_strdel(&file->name);
		ft_strdel(&file->path);
		if (file->subopt)
			ft_free_opt(file->subopt);
		free(file);
	}
}

void	ft_free_opt(t_opt *opt)
{
	if (opt)
	{
		ft_strdel(&opt->path);
		if (opt->files)
			ft_dlst_del(&opt->files, ft_free_file);
		free(opt);
	}
}

void	ft_free_args(t_select *select)
{
	ft_strdel(&select->search);
	if (select->opt)
	{
		ft_free_opt(select->opt);
		select->opt = 0;
	}
}
