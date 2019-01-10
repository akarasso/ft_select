#include "ft_select.h"

static const t_func	g_func[] = {
	{ft_backspace},
	{ft_research},
	{ft_enter},
	{ft_left_arrow},
	{ft_right_arrow},
	{ft_down_arrow},
	{ft_up_arrow},
	{ft_space},
	{ft_open_select},
	{ft_escape},
	{ft_help},
	{ft_print_key},
};

int		get_key(unsigned char *buf)
{
	ft_bzero(buf, SHOWTOUCH_BUFFSIZE + 1);
	if (read(STDIN_FILENO, buf, SHOWTOUCH_BUFFSIZE) < 0)
	{
		ft_err(__LINE__, __FILE__, "Read: Fail to read from STDIN_FILENO");
		return (0);
	}
	return (1);
}

int			ft_read_key(t_select *select)
{
	unsigned char	buf[SHOWTOUCH_BUFFSIZE + 1];
	size_t			index;

	while (!select->stop)
	{
		ft_display(select);
		index = 0;
		if (!get_key(buf))
			return (0);
		while (index < COUNT_OF(g_func) && !g_func[index].exec(buf, select))
			index++;
	}
	return (1);
}
