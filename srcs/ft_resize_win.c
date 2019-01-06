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

void	ft_resize_win(int s)
{
	t_select	*select;
	(void)s;
	select = ft_get_select();
	select->win.width = tgetnum("co");
	select->win.height = tgetnum("li");
}
