/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:39:20 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/05 18:14:55 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		init_screen_size(t_select *select)
{
	char *tmp;

	if ((select->win.width = tgetnum("co")) < 0)
	{
		errorFormat(__LINE__, __FILE__, "Could not find 'co' capability");
		return (0);
	}
	if ((select->win.height = tgetnum("li")) < 0 )
	{
		errorFormat(__LINE__, __FILE__, "Could not find 'li' capability");
		return (0);
	}
	if ((temp = tgetstr("pc", 0x0)))
		select->pc = *temp;
	if ((select->bc = tgetstr("le", 0x0)) == ERR)
	{
		errorFormat(__LINE__, __FILE__, "Could not find 'bc' capability");
		return (0);
	}
	if ((select->up = tgetstr("up", 0x0)) == ERR)
	{
		errorFormat(__LINE__, __FILE__, "Could not find 'up' capability");
		return (0);
	}
	return (1);
}

int		init_term(t_select *select)
{
	int ret;

	if ((name = getenv("TERM")) == NULL || tgetent(NULL, name) == ERR)
		return (0);
	if ((ret = tcgetattr(0, &(select->term))) <= 0)
	{
		if (ret == 0)
			errorFormat(__LINE__, __FILE__, "Terminal type is not defined");
		else if (ret < 0)
			errorFormat(__LINE__, __FILE__, "Could not access the termcap data base");
		return (0);
	}
	select->term_save = select->term_save;
	select->term.c_lflag &= ~(ICANON);
	select->term.c_lflag &= ~(ECHO);
	select->term.c_cc[VMIN] = 1;
	select->term.c_cc[VTIME] = 0;
	select->term.c_cc[VINTR] = 0;
	return (init_screen_size(select));
}
