#include "ft_select.h"

/*
Touch:o
*/

t_opt	*ft_read_dir(t_select *select, char *path)
{
	DIR				*pDir;
	struct dirent	*ent;
	t_opt			*newOpt;
	t_file			*newFile;

	if (!(pDir = opendir(path)))
		return (0x0);
	if (!(newOpt = ft_create_option(path, select->ptr_opt)))
		return (0x0);
	newFile = ft_option_add(newOpt, path, "..");
	newFile->mode =  newFile->mode | LOCK;
	while ((ent = readdir(pDir)) != NULL)
	{
		if (*ent->d_name != '.')
		{
			newFile = ft_option_add(newOpt, path, ent->d_name);
			if (newFile->namelen + 2 > newOpt->padding)
				newOpt->padding = newFile->namelen + 2;
			ft_get_color(newFile);
		}
	}
	if (closedir(pDir) < 0)
		ft_err(__LINE__, __FILE__, "Fail to closed dir");
	return (newOpt);
}

void	ft_try_open_dir(t_select *select, t_file *file)
{
	char	*path;
	t_opt			*newOpt;

	if (!file->path)
		path = ft_strdup(file->name);
	else
		path = ft_3strjoinfree(file->path, "/", file->name, 0);
	if (!access(path, F_OK) && !lstat(path, &file->stat))
		if (S_ISDIR(file->stat.st_mode))
		{
			if ((newOpt = ft_read_dir(select, path)))
			{
				ft_reset_mode(select->ptr_opt->files, (0xFF ^ HIDE));
				select->ptr_opt = newOpt;
				select->ptr_elem = newOpt->files->first;
				file->subopt = newOpt;
			}
		}
	ft_strdel(&path);
}

int		ft_open_select(unsigned char *b, t_select *select)
{
	t_file	*file;

	if (b[0] == 111 && b[1] == 0 && select->mode == SELECT_MOD)
	{
		file = select->ptr_elem->data;
		if ((!select->ptr_opt->parent && !ft_strcmp(file->name, ".."))
			|| !ft_strcmp(file->name, "."))
			return (1);
		if (!ft_strcmp(file->name, "..") && (file->mode & LOCK))
		{
			ft_reset_mode(select->ptr_opt->files, (0xFF ^ HIDE));
			select->ptr_opt = select->ptr_opt->parent;
			select->ptr_elem = select->ptr_opt->files->first;
		}
		else if (file->subopt)
		{
			ft_reset_mode(select->ptr_opt->files, (0xFF ^ HIDE));
			select->ptr_opt = file->subopt;
			select->ptr_elem = select->ptr_opt->files->first;
		}
		else
			ft_try_open_dir(select, file);
		return (1);
	}
	return (0);
}
