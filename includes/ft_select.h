/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:03:07 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 10:02:41 by akarasso         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define SELECT		0b00000001
# define LOCK		0b00000010
# define HIDE		0b00000100

# define SELECT_MOD 0
# define SEARCH_MOD 1
# define HELP_MOD 2

# define SHOWTOUCH_BUFFSIZE 8
# define COUNT_OF(ptr) (sizeof(ptr) / sizeof((ptr)[0]))

typedef struct s_opt	t_opt;

struct	s_opt
{
	char		*path;
	t_dlst		*files;
	t_opt		*parent;
	size_t		padding;
};

typedef struct	s_file
{
	t_opt			*subopt;
	char			color[15];
	char			*path;
	char			*name;
	struct stat		stat;
	size_t			namelen;
	int				mode;
}				t_file;

typedef struct	s_win
{
	size_t			width;
	size_t			height;
	size_t			cols;
	size_t			rows;
}				t_win;

typedef struct	s_select
{
	struct termios	term;
	struct termios	term_saved;
	t_opt			*opt;
	t_opt			*ptr_opt;
	t_dlst_elem		*ptr_elem;
	t_win			win;
	char			mode;
	char			*search;
	int				nselect;
	int				printed;
	int				stop;
}				t_select;

typedef struct	s_func
{
	int		(*exec)(unsigned char *, t_select *);
}				t_func;


/*
**	Options
*/

t_opt		*ft_create_option(char *path, t_opt *parent);
t_file		*ft_option_add(t_opt *opt, char *root, char *name);
t_dlst_elem	*ft_select_next(t_dlst *container, t_dlst_elem *elem, size_t n);
t_dlst_elem	*ft_select_prev(t_dlst *container, t_dlst_elem *elem, size_t n);
void		ft_reset_mode(t_dlst *files, int mode);


/*
**	Init
*/

int		ft_check_termcaps();
void	ft_init_selection();
int		ft_init_screen(t_select *select);
void	ft_reset_term(t_select *select);
int		ft_init_term(t_select *select);

/*
**	Signal
*/

void		ft_catch_signal();

/*
**	Key Handler
*/

int			ft_read_key(t_select *select);
int			ft_print_key(unsigned char *b, t_select *select);
int			ft_enter(unsigned char *b, t_select *select);
int			ft_down_arrow(unsigned char *b, t_select *select);
int			ft_open_select(unsigned char *b, t_select *select);
int			ft_left_arrow(unsigned char *b, t_select *select);
int			ft_research(unsigned char *b, t_select *select);
int			ft_right_arrow(unsigned char *b, t_select *select);
int			ft_space(unsigned char *b, t_select *select);
int			ft_up_arrow(unsigned char *b, t_select *select);
int			ft_escape(unsigned char *b, t_select *select);
int			ft_backspace(unsigned char *b, t_select *select);
int			ft_help(unsigned char *b, t_select *select);

/*
**	Utils
*/

int			ft_putint(int c);
void		ft_err(int line, char *file, char *reason);
t_select	*ft_get_select();
void		ft_free_args(t_select *select);
void		ft_free_opt(t_opt *opt);
void		ft_print_file(t_dlst_elem *elem);
void		ft_print_opt(t_opt *opt);
void		ft_print_args(t_select *select);

/*
**	Display
*/

void		ft_display(t_select *select);
void		ft_toolbar(t_select *select);
void		ft_get_color(t_file *file);
void		ft_fill_line(size_t curr, size_t max);
void		ft_resize_win(int s);
int			ft_toolbar_len(t_select *select);
void		ft_free_file(t_dlst_elem *elem);
void 		ft_display_help(t_select *select);

#endif
