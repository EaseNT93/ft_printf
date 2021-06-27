/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_wr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:11:44 by dpants            #+#    #+#             */
/*   Updated: 2021/06/25 00:11:44 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_dec_in_base(unsigned long long i, int base)
{
	char					*str_i;
	int						c;
	unsigned long long		tmp_i;

	c = 0;
	tmp_i = i;
	if (i == 0)
		return (str_i = ft_strdup("0"));
	while (tmp_i > 0)
	{
		tmp_i /= base;
		c++;
	}
	str_i = malloc(sizeof(char) * (c + 1));
	str_i[c--] = '\0';
	while (i)
	{
		if ((i % base) < 10)
			str_i[c] = (i % base) + 48;
		else
			str_i[c] = (i % base) + 87;
		i /= base;
		c--;
	}
	return (str_i);
}

int	ft_ui_wr(t_flags flags, char *str_i)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
	{
		if (flags.acc >= 0)
			len += ft_other_wr(1, flags.acc - ft_strlen(str_i));
		len += ft_putstr(ft_strlen(str_i), str_i);
	}
	if (flags.acc >= 0 && (ft_strlen(str_i) > (size_t)flags.acc))
		len += ft_other_wr(0, flags.width - ft_strlen(str_i));
	else if (flags.acc > 0)
		len += ft_other_wr(0, flags.width - flags.acc);
	else
		len += ft_other_wr(flags.zero, flags.width - ft_strlen(str_i));
	if (flags.minus == 0)
	{
		if (flags.acc >= 0)
			len += ft_other_wr(1, flags.acc - ft_strlen(str_i));
		len += ft_putstr(ft_strlen(str_i), str_i);
	}
	return (len);
}

int	ft_hex_wr(t_flags flags, int case_size, unsigned int i)
{
	int		len;
	int		c;
	char	*str_i;

	len = 0;
	c = -1;
	if (i == 0 && flags.acc == 0)
	{
		len += ft_other_wr(0, flags.width);
		return (len);
	}
	str_i = ft_dec_in_base(i, 16);
	if (case_size)
		while (str_i[++c])
			str_i[c] = ft_toupper(str_i[c]);
	len += ft_ui_wr(flags, str_i);
	free(str_i);
	return (len);
}
