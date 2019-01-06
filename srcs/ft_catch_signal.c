/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:33:34 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:07:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_stop(int s)
{
	(void)s;
}

void 	ft_resume(int s)
{
	(void)s;
}

/*
**	SIGXCPU => CPU time limit exceeded
**	SIGPROF => Profiling timer expired
**	SIGWINCH => Redim
*/
void	ft_catch_signal()
{
	signal(SIGHUP, ft_clear_exit);
	signal(SIGINT, ft_clear_exit);
	signal(SIGTERM, ft_clear_exit);
	signal(SIGTSTP, ft_stop);
	signal(SIGCONT, ft_resume);
	signal(SIGTTIN, ft_clear_exit);
	signal(SIGTTOU, ft_clear_exit);
	signal(SIGXCPU, ft_clear_exit);
	signal(SIGPROF, ft_clear_exit);
	signal(SIGWINCH, ft_resize_win);
}
