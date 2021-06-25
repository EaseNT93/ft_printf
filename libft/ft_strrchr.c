/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:57:15 by dpants            #+#    #+#             */
/*   Updated: 2021/04/22 12:57:15 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	char	*tmp_str;
	char	*tmp;
	char	tmp_s;

	tmp_str = (char *)str;
	tmp = 0;
	tmp_s = (char)s;
	while (*tmp_str)
	{
		if (*tmp_str == tmp_s)
			tmp = tmp_str;
		tmp_str++;
	}
	if (tmp)
		return (tmp);
	else if (tmp_s == '\0')
		return (tmp_str);
	else
		return (NULL);
}
