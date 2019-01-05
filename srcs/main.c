/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:39 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/05 15:46:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		input(t_dlst *lst, char **argv)
{
	t_opt	*curr;

	while (*argv)
	{
		if (!(curr = ft_memalloc(sizeof(*curr))))
			return (0);
		if (!(curr->name = ft_strdup(*argv)))
			return (0);
		curr->state = UNSELECT;
		ft_dlst_push(lst, curr);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_select select;

	ft_bzero(select, sizeof(t_select));
	if (!(select.lst = ft_dlst_new(0)))
		return (0);
	if (catch_input(select.lst, argv) && init_term(&select))
	{
			
	}
	return 0;
}
