/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:39:20 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 15:07:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_reset_term(t_select *select)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &select->term_saved);
	tputs(tgetstr("ve", NULL), 1, ft_putint);
	tputs(tgetstr("te", NULL), 1, ft_putint);
}

int		ft_init_term(t_select *select)
{
	int		ret;
	char	*name;

	if ((name = getenv("TERM")) == NULL || tgetent(NULL, name) == ERR)
		return (0);
	if ((ret = tcgetattr(STDERR_FILENO, &(select->term))) < 0)
	{
		if (ret == 0)
			ft_err(__LINE__, __FILE__, "Term: undefined");
		else if (ret < 0)
			ft_err(__LINE__, __FILE__, "Termcaps: no database found");
		return (0);
	}
	select->term_saved = select->term;
	select->term.c_lflag &= ~(ICANON | ECHO);
	select->term.c_cc[VMIN] = 1;
	select->term.c_cc[VTIME] = 0;
	return (ft_check_termcaps());
}
