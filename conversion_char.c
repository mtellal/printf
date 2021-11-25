/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:11:22 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/23 17:18:07 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args, int *l_conversion)
{
	int			c;

	c = (char) va_arg(args, int);
	ft_putchar(c, 1);
	*l_conversion += 1;
	return (1);
}
