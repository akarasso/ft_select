/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:28:16 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 15:11:29 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_display_count_selection(t_select *select,
		size_t *curr, int row_toolbar)
{
	int		len_count;
	char	*goto_cmd;

	len_count = ft_nbr_len(select->nselect);
	if (row_toolbar == 2)
	{
		ft_fill_line(*curr, select->win.width);
		goto_cmd = tgoto(tgetstr("cm", 0x0), 0, select->win.height - 1);
		tputs(goto_cmd, STDERR_FILENO, ft_putint);
		(*curr) = 0;
	}
	else
	{
		ft_fill_line((*curr), select->win.width - 20 - len_count);
		(*curr) = select->win.width - 20 - len_count;
	}
	ft_putstr_fd("Nombre de selection:", STDERR_FILENO);
	ft_putnbr_fd(select->nselect, STDERR_FILENO);
	(*curr) += 20 + len_count;
}

void		ft_display_search_mode(t_select *select, size_t *curr)
{
	size_t		len;
	char		*ptr;

	ft_putstr_fd("Recherche:", STDERR_FILENO);
	if (select->search)
	{
		len = ft_strlen(select->search);
		if (10 + len < select->win.width)
		{
			ft_putstr_fd(select->search, STDERR_FILENO);
			(*curr) += len;
		}
		else
		{
			ptr = select->search + len - (select->win.width - 13);
			ft_putstr_fd("...", STDERR_FILENO);
			ft_putstr_fd(ptr, STDERR_FILENO);
			(*curr) += select->win.width;
		}
	}
	else
	{
		ft_putstr_fd("<string>", STDERR_FILENO);
		(*curr) += 8;
	}
}

void		ft_display_select_mode(size_t *curr)
{
	ft_putstr_fd("Mode selection", STDERR_FILENO);
	(*curr) = 14;
}

void		ft_toolbar(t_select *select)
{
	char	*goto_cmd;
	int		row_toolbar;
	size_t	curr;

	curr = 10;
	row_toolbar = ft_toolbar_len(select);
	goto_cmd = tgoto(tgetstr("cm", 0x0), 0, select->win.height - row_toolbar);
	tputs(goto_cmd, STDERR_FILENO, ft_putint);
	ft_putstr_fd(REVCOLOR, STDERR_FILENO);
	if (select->mode == SEARCH_MOD)
		ft_display_search_mode(select, &curr);
	else
		ft_display_select_mode(&curr);
	ft_display_count_selection(select, &curr, row_toolbar);
	ft_fill_line(curr, select->win.width);
	ft_putstr_fd(RESET, STDERR_FILENO);
}
