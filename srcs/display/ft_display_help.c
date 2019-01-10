#include "ft_select.h"

void	print_help_file(int fd)
{
	int		ret;
	char	*line;

	line = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
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
			return print_help_file(fd);
		ft_putstr("...");
	}
}
