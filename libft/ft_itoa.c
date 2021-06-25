/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:13:01 by dpants            #+#    #+#             */
/*   Updated: 2021/05/02 22:13:01 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
{
	int		l;

	l = 0;
	while (n >= 0)
	{
		l++;
		n /= 10;
		if (n == 0)
			return (l);
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	i += ft_nlen(n);
	str[i--] = '\0';
	while (n >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			return (ft_strdup(str));
	}
	return (ft_strdup(str));
}
