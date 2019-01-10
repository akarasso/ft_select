/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:28 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 16:47:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_key(unsigned char *buf)
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
	static unsigned char	buf[SHOWTOUCH_BUFFSIZE + 1];
	size_t					index;
	static t_func			g_func[] = {{ft_backspace}, {ft_research},
		{ft_enter}, {ft_left_arrow}, {ft_right_arrow}, {ft_down_arrow},
		{ft_up_arrow}, {ft_space}, {ft_open_select}, {ft_escape}, {ft_help},
	};

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
