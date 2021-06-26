/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_wr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:14:00 by dpants            #+#    #+#             */
/*   Updated: 2021/06/21 15:14:00 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_char_wr(t_flags flags, char i)
{
	int	len;

	len = 1;
	if (flags.minus == 1)
		ft_putchar_fd(i, 1);
	len += ft_other_wr(0, flags.width - 1);
	if (flags.minus == 0)
		ft_putchar_fd(i, 1);
	return (len);
}
