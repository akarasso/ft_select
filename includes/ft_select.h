/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:07 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/05 18:11:39 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_dlst			lst;
	t_win			win;
	struct termios	term;
	struct termios	term_saved;
	char			pc;
	char*			bc;
	char*			up;
}				t_select;

#endif
