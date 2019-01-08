/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:39 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/08 19:30:27 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		catch_input(t_select *select, t_dlst *lst, char **argv)
{
	t_opt	*curr;

	while (*argv)
	{
		if (!(curr = ft_memalloc(sizeof(*curr))))
			return (0);
		if (!(curr->name = ft_strdup(*argv)))
			return (0);
		if (!(curr->pathname = ft_strdup(*argv)))
			return (0);
		if ((uint)(curr->namelen = ft_strlen(curr->name)) + 2 > select->win.cols)
			select->win.padding = curr->namelen + 2;
		ft_dlst_pushback(lst, curr);
		argv++;
	}
	ft_putnbr(select->win.padding);
	printf("\n");
	getchar();
	return (1);
}

t_select	*ft_get_select()
{
	static t_select select;

	return &select;
}

int main(int argc, char **argv)
{
	t_select *select;

	(void)argc;
	select = ft_get_select();
	if (!(select->options = ft_dlst_new(0)))
		return (0);
	if (catch_input(select, select->options, (argv + 1)) && ft_init_term(select))
	{
		select->ptr_options = select->options;
		select->ptr_elem = select->ptr_options->first;
		ft_catch_signal();
		ft_init_sreen(select);
		ft_enter_in_selection();
		ft_read_key(select);
	}
	ft_reset_term(select);
	return 0;
}
