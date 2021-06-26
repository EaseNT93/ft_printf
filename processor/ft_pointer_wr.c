/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_wr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:20:12 by dpants            #+#    #+#             */
/*   Updated: 2021/06/22 14:20:12 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_zero_p_wr(t_flags flags, char *str_i)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (flags.acc > 0)
		len += ft_other_wr(1, flags.acc - ft_strlen(str_i));
	len += ft_putstr(ft_strlen(str_i), str_i);
	return (len);
}

int	ft_p_wr(t_flags flags, unsigned long long i)
{
	int		len;
	char	*str_i;

	len = 0;
	str_i = ft_dec_in_base(i, 16);
	if (flags.minus == 1)
		len += ft_zero_p_wr(flags, str_i);
	len += ft_other_wr(0, flags.width - ft_strlen(str_i) - 2);
	if (flags.minus == 0)
		len += ft_zero_p_wr(flags, str_i);
	free(str_i);
	return (len);
}
