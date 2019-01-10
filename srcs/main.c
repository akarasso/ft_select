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

int		ft_read_input(t_opt *opt, char **argv)
{
	t_file	*file;

	while (*argv)
	{
		if (!(file = ft_option_add(opt, 0x0, *argv)))
		{
			ft_err(__LINE__, __FILE__, "Read argv: fail to add argv");
			return (0);
		}
		if (file->namelen + 2 > opt->padding)
			opt->padding = file->namelen + 2;
		ft_get_color(file);
		argv++;
	}
	return (1);
}

t_select	*ft_get_select()
{
	static t_select select;

	return &select;
}

int ft_usage(void)
{
	return (0);
}

int main(int argc, char **argv)
{
	t_select *select;

	if (argc == 1)
		return ft_usage();
	select = ft_get_select();
	if (!(select->opt = ft_create_option(0x0, 0x0)))
		return (0);
	select->term_saved = select->term;
	if (ft_read_input(select->opt, &argv[1]) && ft_init_term(select))
	{
		select->ptr_opt = select->opt;
		select->ptr_elem = select->opt->files->first;
		ft_catch_signal();
		ft_init_screen(select);
		ft_init_selection();
		ft_read_key(select);
	}
	ft_reset_term(select);
	ft_print_args(select);
	ft_free_args(select);
	return 0;
}
