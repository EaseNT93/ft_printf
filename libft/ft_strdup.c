/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:04:15 by dpants            #+#    #+#             */
/*   Updated: 2021/04/29 12:04:15 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (NULL == new_str)
		return (NULL);
	while (i < ft_strlen(str))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
