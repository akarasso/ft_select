/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:41:30 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/05 16:46:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	errorFormat(int line, char *file, char *reason)
{
	ft_putstr_fd("'", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("' ", 2);
	ft_putstr_fd("Error line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(reason, 2);
	ft_putendl();
}
