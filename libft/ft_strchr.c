/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:27:35 by dpants            #+#    #+#             */
/*   Updated: 2021/04/22 14:27:35 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	while (*str)
	{
		if (*str == s)
			return ((char *)str);
		str++;
	}
	if (s == '\0')
		return ((char *)str);
	return (NULL);
}
