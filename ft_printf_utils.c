/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:03:44 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/23 18:44:25 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sub(char *s, int i, int *nbChar)
{
	char		*sub;

	if (*(s + 1) == '\0')
		sub = ft_substr(s - i, 0, i + 1);
	else
		sub = ft_substr(s - i, 0, i);
	ft_putstr_fd(sub, 1);
	*nbChar += ft_strlen(sub);
	free(sub);
}
