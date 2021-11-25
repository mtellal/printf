/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:52:48 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/23 17:24:44 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base10(va_list args, char c, int *l_conversion)
{
	unsigned long int	n;
	long int			number;
	char				*s;

	if (c == 'i' || c == 'd')
	{
		number = (long int) va_arg(args, long int);
		s = ft_itoa(number);
	}
	else
	{
		n = (unsigned long int) va_arg(args, unsigned long int);
		s = ft_untoa(n);
	}
	ft_putstr_fd(s, 1);
	*l_conversion += ft_strlen(s);
	free(s);
	return (1);
}
