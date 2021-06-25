/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_wr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:17:29 by dpants            #+#    #+#             */
/*   Updated: 2021/06/22 14:17:29 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_i_len(int i)
{
	int	i_len;

	i_len = 0;
	while (i >= 0)
	{
		i_len++;
		i /= 10;
		if (i == 0)
			return (i_len);
	}
}

int	ft_int_zero_wr(t_flags flags, int i)
{
	int		len;
	char	*str_i;

	len = 0;
	if (i < 0)
	{
		write(1, '-', 1);
		len++;
		if (i == -2147483648)
			str_i = ft_strdup("2147483648");
		else
			i = -i;
	}
	if (!str_i)
		str_i = ft_itoa(i);
	if (flags.acc > 0)
		len += ft_other_wr(1, flags.acc, ft_strlen(str_i));
	len += ft_putstr(ft_strlen(str_i), str_i);
	free(str_i);
	return (len);
}

int	ft_int_wr(t_flags flags, int i)
{
	int len;

	len = 0;
	if (i == 0 && flags.acc == 0)
	{
		len += ft_other_wr(0, flags.width, 0);
		return (len);
	}
	if (flags.minus == 1)
		len += ft_int_zero_wr(flags, i);
	if (flags.acc >= 0)
	{
		if (flags.acc < ft_i_len(i))
			flags.acc = ft_i_len(i);
		len += ft_other_wr(0, flags.width, flags.acc);
	}
	else
	{
		if (i < 0)
			flags.width--;
		len += ft_other_wr(flags.zero , flags.width, ft_i_len(i));
	}
	if (flags.minus == 0)
		len += ft_int_zero_wr(flags, i);
	return (len);
}
