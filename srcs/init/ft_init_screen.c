/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:15:55 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 13:15:56 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

int		ft_init_screen(t_select *select)
{
	struct winsize	wsize;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &wsize);
	select->win.width = wsize.ws_col;
	select->win.height = wsize.ws_row;
	return (1);
}
