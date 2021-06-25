/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:59:15 by dpants            #+#    #+#             */
/*   Updated: 2021/04/27 19:59:15 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int s, size_t n)
{
	unsigned char	*tmp_str;
	unsigned char	tmp_s;
	size_t			i;

	tmp_str = (unsigned char *)str;
	tmp_s = (unsigned char)s;
	i = 0;
	while (i < n)
	{
		if (*tmp_str == tmp_s)
			return (tmp_str);
		tmp_str++;
		i++;
	}
	return (NULL);
}
