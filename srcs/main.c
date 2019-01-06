/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:39 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:34:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		catch_input(t_dlst *lst, char **argv)
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
		argv++;
	}
	return (1);
}

t_select	*ft_get_select()
{
	static t_select select = 0;

	return &select;
}

int main(int argc, char **argv)
{
	t_select *select;

	(void)argc;
	select = ft_get_select();
	if (!(select->lst = ft_dlst_new(0)))
		return (0);
	if (catch_input(select->lst, (argv + 1)) && init_term(select))
	{
		ft_catch_signal();

	}
	return 0;
}
