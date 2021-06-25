/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:56:43 by dpants            #+#    #+#             */
/*   Updated: 2021/04/22 12:56:43 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int s, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	tmp_s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tmp_s[i] = s;
		i++;
	}
	return (tmp_s);
}
