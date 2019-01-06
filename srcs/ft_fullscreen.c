/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullscreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:36:12 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:37:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fullscreen()
{
	t_select	*select;

	select = ft_get_select();
	tputs(tgetstr("vi", 0), 1, ft_putint);
	tputs(tgetstr("ti", 0), 1, ft_putint);
}
