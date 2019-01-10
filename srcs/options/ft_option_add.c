#include "ft_select.h"

t_file	*ft_option_add(t_opt *opt, char *root, char *name)
{
	t_file	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (0x0);
	if (!name || !(new->name = ft_strdup(name)))
	{
		free(new);
		return (0x0);
	}
	if (root && !(new->path = ft_strdup(root)))
	{
		free(new->name);
		free(new);
		return (0);
	}
	new->namelen = ft_strlen(name);
	ft_dlst_pushback(opt->files, new);
	return (new);
}
