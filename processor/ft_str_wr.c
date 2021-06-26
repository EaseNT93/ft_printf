/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_wr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:04:14 by dpants            #+#    #+#             */
/*   Updated: 2021/06/22 14:04:14 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_str_width(t_flags flags, char *str)
{
	int	len;

	len = 0;
	if (flags.acc >= 0)
	{
		len += ft_other_wr(0, flags.acc - ft_strlen(str));
		len += ft_putstr(flags.acc, str);
	}
	else
		len += ft_putstr(ft_strlen(str), str);
	return (len);
}

int	ft_str_wr(t_flags flags, char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	if (flags.acc >= 0 && (size_t)flags.acc > ft_strlen(str))
		flags.acc = ft_strlen(str);
	if (flags.minus == 1)
		len += ft_str_width(flags, str);
	if (flags.acc >= 0)
		len += ft_other_wr(0, flags.width - flags.acc);
	else
		len += ft_other_wr(0, flags.width - ft_strlen(str));
	if (flags.minus == 0)
		len += ft_str_width(flags, str);
	return (len);
}
