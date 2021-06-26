/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_wr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:05 by dpants            #+#    #+#             */
/*   Updated: 2021/06/21 15:51:05 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_other_wr(int zero_flag, int width)
{
	int	len;

	len = 0;
	while (width > 0)
	{
		if (zero_flag)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width--;
		len++;
	}
	return (len);
}

int	ft_putstr(int acc, char *str)
{
	int	len;

	len = 0;
	while (str[len] && len < acc)
		len++;
	write(1, str, len);
	return (len);
}
