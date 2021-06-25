/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:39:28 by dpants            #+#    #+#             */
/*   Updated: 2021/04/29 11:39:28 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_count, size_t n_size)
{
	void	*tmp;

	tmp = (void *)malloc(n_count * n_size);
	if (NULL == tmp)
		return (NULL);
	ft_bzero(tmp, n_count * n_size);
	return (tmp);
}
