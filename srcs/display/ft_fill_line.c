/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:28:05 by akarasso          #+#    #+#             */
/*   Updated: 2019/01/10 14:16:05 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_fill_line(size_t curr, size_t max)
{
	while (curr < max)
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		curr++;
	}
}
