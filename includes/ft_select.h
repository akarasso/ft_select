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
# include <sys/types.h>
# include <sys/stat.h>

# define UNSELECT	0
# define SELECT		1
# define UNLOCK		0
# define LOCK		1

# define SHOWTOUCH_BUFFSIZE 8
# define COUNT_OF(ptr) (sizeof(ptr) / sizeof((ptr)[0]))

typedef struct	s_opt
{
	struct stat	stat;
	char		*pathname;
	char		*name;
	t_dlst		*subfiles;
	int			namelen;
	int			state;
	char		lock;
}				t_opt;

typedef struct	s_win
{
	uint		width;
	uint		height;
	uint		padding;
	uint		cols;
	uint		rows;
}				t_win;

typedef struct	s_select
{
	t_dlst			*options;
	t_dlst			*ptr_options;
	t_dlst_elem		*ptr_elem;
	t_win			win;
	struct termios	term;
	struct termios	term_saved;
	int				nselect;
}				t_select;

typedef struct	s_func
{
	int		(*exec)(unsigned char *, t_select *);
}				t_func;

void		ft_resize_win(int s);
void		ft_clear_exit(int s);
void		ft_err(int line, char *file, char *reason);
void		ft_catch_signal();
t_select	*ft_get_select();
int			ft_putint(int c);
int			ft_check_termcaps();
int			ft_init_term(t_select *select);
int			ft_read_key(t_select *select);
void		ft_enter_in_selection();
void		ft_display(t_select *select);
int			ft_init_sreen(t_select *select);
void		ft_free_opt(void *data);
void		ft_reset_term(t_select *select);


/*
**	Function
*/
int		ft_print_key(unsigned char *b, t_select *select);
int		ft_enter(unsigned char *b, t_select *select);
int		ft_down_arrow(unsigned char *b, t_select *select);
int		ft_goto(unsigned char *b, t_select *select);
int		ft_left_arrow(unsigned char *b, t_select *select);
int		ft_research(unsigned char *b, t_select *select);
int		ft_right_arrow(unsigned char *b, t_select *select);
int		ft_space(unsigned char *b, t_select *select);
int		ft_up_arrow(unsigned char *b, t_select *select);
int		ft_escape(unsigned char *b, t_select *select);
int		ft_backspace(unsigned char *b, t_select *select);

#endif
