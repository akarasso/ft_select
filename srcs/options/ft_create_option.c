/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:18:44 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 13:19:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_opt	*ft_create_option(char *path, t_opt *parent)
{
	t_opt	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (0x0);
	if (!(new->files = ft_dlst_new(0x0)))
	{
		free(new);
		return (0x0);
	}
	new->parent = parent;
	new->path = ft_strdup(path);
	return (new);
}
