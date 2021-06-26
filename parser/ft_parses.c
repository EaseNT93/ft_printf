/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:32:10 by dpants            #+#    #+#             */
/*   Updated: 2021/06/21 12:32:10 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_check(int i)
{
	if (i == 'c' || i == 's' || i == 'p' || i == 'd' || i == 'i' \
	|| i == 'u' || i == 'x' || i == 'X' || i == '%')
		return (1);
	else
		return (0);
}

int	ft_flag_check(int i)
{
	if (i == '-' || i == '0' || i == '.' || i == '*')
		return (1);
	else
		return (0);
}

int	ft_type_parse(va_list ap, t_flags flags, int i)
{
	int	len;

	len = 0;
	if (i == 'c')
		len += ft_char_wr(flags, va_arg(ap, int));
	else if (i == 's')
		len += ft_str_wr(flags, va_arg(ap, char *));
	else if (i == 'p')
		len += ft_p_wr(flags, va_arg(ap, unsigned long long));
	else if (i == 'd' || i == 'i')
		len += ft_int_wr(flags, va_arg(ap, int));
	else if (i == 'u')
		len += ft_un_int_wr(flags, va_arg(ap, unsigned int));
	else if (i == 'x')
		len += ft_hex_wr(flags, 0, va_arg(ap, unsigned int));
	else if (i == 'X')
		len += ft_hex_wr(flags, 1, va_arg(ap, unsigned int));
	else if (i == '%')
		len += ft_perc_wr(flags);
	return (len);
}
