/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:18:51 by dpants            #+#    #+#             */
/*   Updated: 2021/04/28 11:18:51 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] && j < n)
		j++;
	if (j < n - 1 && n > 0)
	{
		while (j + i < (n - 1) && src[i])
		{
			dest[j + i] = src[i];
			i++;
		}
	}
	if (j < n)
		dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
