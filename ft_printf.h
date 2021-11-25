/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:51:44 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/24 16:16:07 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int						ft_printf(const char *s, ...);
int						print_char(va_list arg, int *l_conversion);
int						print_string(va_list arg, int *l_conversion);
int						print_percent(int *l_conversion);
void					print_sub(char *s, int i, int *nbChar);
char					ft_belong(char c);
int						print_base10(va_list args, char c, int *l_conversion);
int						print_base16(va_list args, char c, int *l_sonversion);
char					*convert_int2_hex(long long nb, int up);

#endif
