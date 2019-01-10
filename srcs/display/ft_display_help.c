/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:27:56 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 14:15:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_help_file(int fd)
{
	int		ret;
	char	*line;

	line = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_strdel(&line);
	}
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_strdel(&line);
	if (ret < 0)
		ft_err(__LINE__, __FILE__, "Fail to read help file");
}

void	ft_display_help(t_select *select)
{
	int		fd;

	if ((fd = open("help", O_RDONLY)) < 0)
		ft_err(__LINE__, __FILE__, "Fail to open help file");
	else
	{
		if (select->win.width > 90 && select->win.height > 18)
			return (print_help_file(fd));
		ft_putstr_fd("...", STDERR_FILENO);
	}
}
