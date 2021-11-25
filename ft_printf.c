/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:45:58 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/25 15:35:34 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_belong(char c)
{
	char	*pattern;

	pattern = "cspdiuxX%";
	while (*pattern)
	{
		if (c == *pattern)
			return (*pattern);
		pattern++;
	}
	return (0);
}

int	redirect_conversion(char c, va_list args, int *l_conversion)
{
	if (c == 'c')
		return (print_char(args, l_conversion));
	else if (c == '%')
		return (print_percent(l_conversion));
	else if (c == 's')
		return (print_string(args, l_conversion));
	else if (c == 'i' || c == 'd' || c == 'u')
		return (print_base10(args, c, l_conversion));
	else
		return (print_base16(args, c, l_conversion));
}

void	find_conversion(char **s, va_list args, int *l_conversion, int *j)
{
	char	conversion;

	conversion = ft_belong(*(*s + 1));
	if (conversion)
	{
		*j = redirect_conversion(conversion, args, l_conversion);
		if (*j)
			*s += *j + 1;
	}
	else
		*j = 0;
}

int	iterate_string(char *s, va_list args)
{
	int			i;
	int			nbchar;	
	int			j;

	j = 0;
	i = 0;
	nbchar = 0;
	while (*s)
	{
		if (*s == '%' || *(s + 1) == '\0')
		{
			if (*(s + 1) == '\0' && *s == '%')
				return (nbchar);
			print_sub(s, i, &nbchar);
			find_conversion(&s, args, &nbchar, &j);
			i = 0;
		}
		if (!j)
		{
			s++;
			i++;
		}
		j = 0;
	}
	return (nbchar);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			nbchar;

	va_start(args, s);
	nbchar = iterate_string((char *)s, args);
	va_end(args);
	return (nbchar);
}
