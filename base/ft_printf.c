/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:31:38 by dpants            #+#    #+#             */
/*   Updated: 2021/06/17 14:31:38 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_flags_init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.star = 0;
	flags.acc = -1;
	flags.type = 0;
	return (flags);
}

int	ft_flags_parse(const char *data, va_list ap, t_flags *flags, int i)
{
	while (data[i])
	{
		if (!ft_isdigit(data[i]) && !ft_flag_check(data[i]) && !ft_type_check(data[i]))
			break ;
		if (data[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (data[i] == '.')
			i = ft_dot_flag(data, ap, flags, i);
		if (data[i] == '-')
			flags = ft_minus_flag(*flags);
		if (data[i] == '*')
			flags = ft_star_flag(ap, flags);
		if (ft_isdigit(data[i]))
			flags = ft_digit_flag(flags, data[i]);
		if (ft_type_check(data[i]))
		{
			flags->type = data[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_format_parse(const char *data, va_list ap)
{
	int		len;
	int		i;
	t_flags	flags;

	len = 0;
	i = 0;
	while (1)
	{
		flags = ft_flags_init();
		if (!data[i])
			break ;
		if (data[i] == '%' && data[i + 1])
		{
			i = ft_flags_parse(data, ap, &flags, i + 1);
			if (ft_type_check(data[i]))
				len += ft_type_parse(ap, flags, flags.type);
			else if (data[i])
			{
				ft_putchar_fd(data[i], 1);
				len++;
			}
		}
		else if (data[i] != '%')
		{
			ft_putchar_fd(data[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;
	const char	*data;

	if (NULL == format)
		return (0);
	data = ft_strdup(format);
	if (NULL == data)
		return (-1);
	va_start(ap, format);
	len = ft_format_parse(data, ap);
	va_end(ap);
	free(data);
	return (len);
}
