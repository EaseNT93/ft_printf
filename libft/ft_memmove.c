/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:51:12 by dpants            #+#    #+#             */
/*   Updated: 2021/04/27 19:51:12 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dest && !src)
		return (NULL);
	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	if (dest < src)
		while (n--)
			*tmp_d++ = *tmp_s++;
	else
		while (n--)
			*(tmp_d + n) = *(tmp_s + n);
	return (dest);
}
