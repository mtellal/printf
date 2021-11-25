/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertInt2Hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:27:58 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/23 17:32:04 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ndigit(long long nb)
{
	int					digit;
	unsigned long long	unb;

	digit = 1;
	if (nb < 0)
	{
		unb = (unsigned long long) nb;
		while (unb >= 16)
		{
			unb /= 16;
			digit++;
		}
	}
	else
	{
		while (nb >= 16)
		{
			nb /= 16;
			digit++;
		}
	}
	return (digit);
}

char	*convert_int2_hex(long long nb, int up)
{
	char				*s;
	int					zero;
	char				*tab1;
	char				*tab2;
	unsigned long long	unb;

	tab1 = "0123456789abcdef";
	tab2 = "0123456789ABCDEF";
	zero = ndigit(nb);
	unb = (unsigned long long) nb;
	s = (char *) malloc(sizeof(char) * zero + 1);
	if (s == NULL)
		return (NULL);
	s[zero--] = '\0';
	if (unb == 0)
		s[zero] = '0';
	while (unb > 0)
	{
		if (up)
			s[zero--] = tab2[(unb % 16)];
		else
			s[zero--] = tab1[(unb % 16)];
		unb /= 16;
	}
	return (s);
}
