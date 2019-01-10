/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:54 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 13:18:54 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_reset_mode(t_dlst *files, int mode)
{
	t_dlst_elem		*elem;
	t_file			*file;

	if (!files)
		return ;
	elem = files->first;
	while (elem)
	{
		file = elem->data;
		file->mode &= mode;
		elem = elem->next;
	}
}
