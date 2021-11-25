/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:52:30 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/23 17:27:49 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args, int *l_conversion)
{
	char	*s;

	s = (char *) va_arg(args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		*l_conversion += 6;
		return (1);
	}
	ft_putstr_fd(s, 1);
	*l_conversion += ft_strlen(s);
	return (1);
}
