/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:07 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 19:43:54 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

# define UNSELECT	0
# define SELECT		1

typedef struct	termios	t_termios;

typedef struct	s_opt
{
	char	*name;
	int		state;
}				t_opt;

typedef struct	s_win
{
	int		width;
	int		height;
}				t_win;

typedef struct	s_select
{
	t_dlst			*lst;
	t_win			win;
	struct termios	term;
	struct termios	term_saved;
	char			pc;
	char			*bc;
	char			*up;
}				t_select;


void		ft_resize_win(int s);
void		ft_clear_exit(int s);
void		ft_err(int line, char *file, char *reason);
int			init_term(t_select *select);
void		ft_catch_signal();
t_select	*ft_get_select();

#endif
