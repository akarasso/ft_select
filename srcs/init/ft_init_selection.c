/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:36:12 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 15:07:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_selection(void)
{
	t_select *select;

	select = ft_get_select();
	tcsetattr(STDERR_FILENO, TCSANOW, &select->term);
	tputs(tgetstr("vi", 0), 1, ft_putint);
	tputs(tgetstr("ti", 0), 1, ft_putint);
}
