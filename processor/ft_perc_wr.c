/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_wr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:51:36 by dpants            #+#    #+#             */
/*   Updated: 2021/06/23 21:51:36 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_perc_wr(t_flags flags)
{
	int len;

	len = 1;
	if (flags.minus == 1)
		write(1, "%", 1);
	len += ft_other_wr(flags.zero, flags.width, 1);
	if (flags.minus == 0)
		write(1, "%", 1);
	return (len);
}
