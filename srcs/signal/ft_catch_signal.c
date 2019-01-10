/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:33:34 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 14:05:52 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

static void	suspend_signal_handler(void)
{
	ft_reset_term(ft_get_select());
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		stop_signal_handler(void)
{
	t_select *select;

	select = ft_get_select();
	ft_reset_term(select);
	ft_free_args(select);
	exit(0);
}

void		signal_handler(int signo)
{
	t_select *select;

	if (signo == SIGTSTP)
		suspend_signal_handler();
	else if (signo == SIGINT || signo == SIGABRT
		|| signo == SIGSTOP || signo == SIGKILL || signo == SIGQUIT)
		stop_signal_handler();
	else if (signo == SIGCONT)
	{
		select = ft_get_select();
		ft_init_term(select);
		ft_init_screen(select);
		ft_init_selection();
		ft_catch_signal();
		ft_display(select);
	}
	else if (signo == SIGWINCH)
		ft_resize_win(SIGWINCH);
}

void		ft_catch_signal(void)
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
