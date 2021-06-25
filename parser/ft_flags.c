/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:43:09 by dpants            #+#    #+#             */
/*   Updated: 2021/06/21 13:43:09 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_dot_flag(const char *data, va_list ap, t_flags *flags, int i)
{
	i++;
	if (data[i] == '*')
	{
		flags->acc = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->acc = 0;
		while (ft_isdigit(data[i]))
		{
			flags->acc = flags->acc * 10 + data[i] - '0';
			i++;
		}
	}
	return (i);
}

t_flags	ft_minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_star_flag(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags	ft_digit_flag(t_flags flags, char i)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = flags.width * 10 + i - '0';
	return (flags);
}
