#include "ft_select.h"

/*
Touch:o
*/

void	ft_read_dir(t_select *select, t_opt *opt)
{
	DIR				*pDir;
	struct dirent	*ent;

	if (!(pDir = opendir(opt->pathname)))
		return;
	opt->subfiles = ft_dlst_new(0x0);
	select->win.padding = 0;
	while ((ent = readdir(pDir)) != NULL)
	{
		if (!ft_strcmp(ent->d_name, ".."))
			catch_input(select, opt->subfiles, (char*[2]){&(*ent->d_name), 0});
		else if (*ent->d_name != '.')
			catch_input(select, opt->subfiles, (char*[2]){&(*ent->d_name), 0});
    }
	select->ptr_options = opt->subfiles;
	select->ptr_elem = opt->subfiles->first;
}

int		ft_is_dir(t_opt	*opt)
{
	if (!lstat(opt->pathname, &opt->stat))
		return (S_ISDIR(opt->stat.st_mode) ? 1 : 0);
	return (0);
}

int		ft_open_select(unsigned char *b, t_select *select)
{
	t_opt	*opt;

	if (b[0] == 111 && b[1] == 0)
	{
		opt = select->ptr_elem->data;
		if (!access(opt->name, F_OK) && ft_is_dir(opt))
			ft_read_dir(select, opt);
		return (1);
	}
	return (0);
}
