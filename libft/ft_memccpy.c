/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:50:31 by dpants            #+#    #+#             */
/*   Updated: 2021/04/22 20:50:31 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int s, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;
	unsigned char	tmp_smb;

	i = 0;
	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	tmp_smb = (unsigned char)s;
	while (i < n)
	{
		*tmp_d++ = *tmp_s++;
		i++;
		if (*(tmp_s - 1) == tmp_smb)
			return (tmp_d);
	}
	return (NULL);
}
