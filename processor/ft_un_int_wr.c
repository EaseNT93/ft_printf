/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_wr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:53:56 by dpants            #+#    #+#             */
/*   Updated: 2021/06/25 13:53:56 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_un_int_wr(t_flags flags, unsigned int i)
{
	int		len;
	char	*str_i;

	len = 0;
	if (i == 0 && flags.acc == 0)
	{
		len += ft_other_wr(0, flags.width, 0);
		return (len);
	}
	str_i = ft_dec_in_base(i, 10);
	len += ft_ui_wr(flags, str_i);
	free(str_i);
	return (len);
}