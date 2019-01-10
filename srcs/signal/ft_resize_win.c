/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:54:38 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 19:44:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

void	ft_resize_win(int s)
{
	t_select		*select;
	struct winsize	wsize;

	(void)s;
	select = ft_get_select();
	ioctl(STDERR_FILENO, TIOCGWINSZ, &wsize);
	select->win.width = wsize.ws_col;
	select->win.height = wsize.ws_row;
	ft_display(select);
}
