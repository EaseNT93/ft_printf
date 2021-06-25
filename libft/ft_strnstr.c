/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:44:21 by dpants            #+#    #+#             */
/*   Updated: 2021/04/28 14:44:21 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*tofind == '\0')
		return ((char *)src);
	while (i < n && src[i])
	{
		j = 0;
		while (src[i + j] == tofind[j] && (i + j) < n)
		{
			j++;
			if (!tofind[j])
				return ((char *)src + i);
		}
		i++;
	}
	return (NULL);
}
