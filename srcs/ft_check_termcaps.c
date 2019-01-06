/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_termcaps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:19:45 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 19:46:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check_screen()
{
	if (!tgetstr("cl", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'cl': no clear screen");
		return (0);
	}
	if (!tgetstr("cm", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'cm': cursor can't make goto");
		return (0);
	}
	if (tgetnum("co") < 0)
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'co': Can't get screen width");
		return (0);
	}
	if (tgetnum("li") < 0)
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'li': Can't get screen height");
		return (0);
	}
	return (1);
}

int		check_cursor()
{
	if (!tgetstr("vi", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'vi': no cursor invisibility");
		return (0);
	}
	if (!tgetstr("ve", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 've': no cursor visibility");
		return (0);
	}
	if (!tgetstr("ti", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'ti': no fullscreen");
		return (0);
	}
	if (!tgetstr("te", 0x0))
	{
		ft_err(__LINE__, __FILE__, "Termcaps: 'te': no resume fullscreen");
		return (0);
	}
	return (1);
}

int		ft_check_termcaps()
{
	if (!check_cursor()) {
		/* code */
	}
	return (1);
}
