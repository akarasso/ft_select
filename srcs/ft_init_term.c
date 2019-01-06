/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:39:20 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:23:54 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_term(t_select *select)
{
	int		ret;
	char	*name;

	if ((name = getenv("TERM")) == NULL || tgetent(NULL, name) == ERR)
		return (0);
	if ((ret = tcgetattr(0, &(select->term))) < 0)
	{
		if (ret == 0)
			ft_err(__LINE__, __FILE__, "Term: undefined");
		else if (ret < 0)
			ft_err(__LINE__, __FILE__, "Termcaps: no database found");
		return (0);
	}
	select->term_saved = select->term;
	select->term.c_lflag &= ~(ICANON);
	select->term.c_lflag &= ~(ECHO);
	select->term.c_cc[VMIN] = 1;
	select->term.c_cc[VTIME] = 0;
	select->term.c_cc[VINTR] = 0;
	return (check_termcaps(select));
}
