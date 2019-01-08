/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:33:34 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/08 19:28:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	suspend_signal_handler(void)
{
	ft_reset_term(ft_get_select());
	signal(SIGTSTP, SIG_DFL);
}

void 	stop_signal_handler(void)
{
	ft_reset_term(ft_get_select());
	exit(1);
}

void		signal_handler(int signo)
{
	t_select *select;

	select = ft_get_select();
	if (signo == SIGTSTP)
		suspend_signal_handler();
	else if (signo == SIGINT || signo == SIGABRT
		|| signo == SIGSTOP || signo == SIGKILL || signo == SIGQUIT)
		stop_signal_handler();
	else if (signo == SIGCONT)
	{
		ft_init_term(select);
		ft_init_sreen(select);
		ft_display(select);
	}
	else if (signo == SIGWINCH)
	{
		ft_init_sreen(select);
		ft_display(select);
	}
}

/*
**	SIGXCPU => CPU time limit exceeded
**	SIGPROF => Profiling timer expired
**	SIGWINCH => Redim
*/
void	ft_catch_signal()
{
	signal(SIGWINCH, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTTOU, signal_handler);
	signal(SIGPROF, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTTIN, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGXCPU, signal_handler);
}
