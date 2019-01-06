/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 16:41:30 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/06 18:01:03 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err(int line, char *file, char *reason)
{
	ft_putstr_fd("'", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("' ", 2);
	ft_putstr_fd("Error line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(reason, 2);
	ft_putendl("");
}
