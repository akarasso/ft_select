/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:18:59 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:33:45 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_screen_size(t_select *select)
{
	char *tmp;

	select->win.width = tgetnum("co");
	select->win.height = tgetnum("li");
	return (1);
}
