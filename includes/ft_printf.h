/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:54 by dpants            #+#    #+#             */
/*   Updated: 2021/06/17 14:52:54 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_flags
{
	int	width;
	int	acc;
	int	type;
	int	minus;
	int	star;
	int	zero;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_type_parse(va_list ap, t_flags flags, int i);

int		ft_dot_flag(const char *data, va_list ap, t_flags *flags, int i);
t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_star_flag(va_list ap, t_flags flags);
t_flags	ft_digit_flag(t_flags flags, char i);

int		ft_type_parse(va_list ap, t_flags flags, int i);
int		ft_flag_check(int i);
int		ft_type_check(int i);

int		ft_char_wr(t_flags flags, char i);
int		ft_str_wr(t_flags flags, char *str);
int		ft_prec_wr(t_flags flags);
int		ft_int_wr(t_flags flags, int i);
int		ft_un_int_wr(t_flags flags, unsigned int i);
int		ft_p_wr(t_flags flags, unsigned long long i);
int		ft_ui_wr(t_flags flags, char *str_i);

char	*ft_dec_in_base(unsigned long long i, int base);
int		ft_ui_wr(t_flags flags, char *str_i);
int		ft_other_wr(int zero_flag, int width, int arg_len);
int		ft_putstr(int acc, char *str);

#endif