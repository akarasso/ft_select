#include "ft_select.h"

t_opt	*ft_create_option(char *path, t_opt *parent)
{
	t_opt	*new;

	if (!(new = ft_memalloc(sizeof *new)))
		return (0x0);
	if (!(new->files = ft_dlst_new(0x0)))
	{
		free(new);
		return (0x0);
	}
	new->parent = parent;
	new->path = ft_strdup(path);
	return (new);
}
