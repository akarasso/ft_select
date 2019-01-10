/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:33:15 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 12:33:15 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_help(unsigned char *b, t_select *select)
{
	if (b[0] == 104 && !b[1]
		&& (select->mode == SELECT_MOD || select->mode == HELP_MOD))
	{
		if (select->mode == SELECT_MOD)
			select->mode = HELP_MOD;
		else
			select->mode = SELECT_MOD;
		return (1);
	}
	return (0);
}
