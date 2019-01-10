/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:24 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 13:18:17 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_opt	*ft_read_dir(t_select *select, char *path)
{
	DIR				*p_dir;
	struct dirent	*ent;
	t_opt			*new_opt;
	t_file			*new_file;

	if (!(p_dir = opendir(path)))
		return (0x0);
	if (!(new_opt = ft_create_option(path, select->ptr_opt)))
		return (0x0);
	new_file = ft_option_add(new_opt, path, "..");
	new_file->mode = new_file->mode | LOCK;
	while ((ent = readdir(p_dir)) != NULL)
	{
		if (*ent->d_name != '.')
		{
			new_file = ft_option_add(new_opt, path, ent->d_name);
			if (new_file->namelen + 2 > new_opt->padding)
				new_opt->padding = new_file->namelen + 2;
			ft_get_color(new_file);
		}
	}
	if (closedir(p_dir) < 0)
		ft_err(__LINE__, __FILE__, "Fail to closed dir");
	return (new_opt);
}

void	ft_try_open_dir(t_select *select, t_file *file)
{
	char	*path;
	t_opt	*new_opt;

	if (!file->path)
		path = ft_strdup(file->name);
	else
		path = ft_3strjoinfree(file->path, "/", file->name, 0);
	if (!access(path, F_OK) && !lstat(path, &file->stat))
		if (S_ISDIR(file->stat.st_mode))
		{
			if ((new_opt = ft_read_dir(select, path)))
			{
				ft_reset_mode(select->ptr_opt->files, (0xFF ^ HIDE));
				select->ptr_opt = new_opt;
				select->ptr_elem = new_opt->files->first;
				file->subopt = new_opt;
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
