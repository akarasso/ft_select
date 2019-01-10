#include "ft_select.h"

int		ft_strendswith(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}

void	ft_get_color(t_file *file)
{
	char	*path;

	if (!file->path)
		path = ft_strdup(file->name);
	else
		path = ft_3strjoinfree(file->path, "/", file->name, 0);
	if (!access(path, F_OK) && !lstat(path, &file->stat))
	{
		if (S_ISDIR(file->stat.st_mode))
			ft_strcpy(file->color, "\033[01;34m");
		else if (ft_strendswith(file->name, ".o"))
			ft_strcpy(file->color, "\033[34m");
		else if (ft_strendswith(file->name, ".c"))
			ft_strcpy(file->color, "\033[32m");
		else if (!ft_strcmp(file->name, "Makefile"))
			ft_strcpy(file->color, "\033[33m");
		else if (file->stat.st_mode & S_IXUSR)
			ft_strcpy(file->color, "\033[91m");
		else if (S_ISLNK(file->stat.st_mode))
			ft_strcpy(file->color, "\033[35m");
	}
	ft_strdel(&path);
}
