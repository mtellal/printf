/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:19:38 by mtellal           #+#    #+#             */
/*   Updated: 2021/11/24 17:14:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	zero_char(char *s)
{
	int		i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] == '0' && s[i + 1])
		i++;
	if (i > 0 && s[i + 1] == '\0')
		return (1);
	return (0);
}

char	*trim_zero(char *s)
{
	char	*ss;
	int		i;

	i = 0;
	if (*s == '0' && *(s + 1) == '\0')
		return (s);
	while (s[i] && s[i] == '0')
		i++;
	ss = ft_strdup(s + i);
	free(s);
	return (ss);
}

char	*trim_char(char *s)
{
	char		*sub;
	int			len_s;

	sub = NULL;
	len_s = ft_strlen(s);
	if (len_s > 8)
	{
		if (len_s >= 8)
			sub = ft_substr_free(s, len_s - 8, 8);
		if (zero_char(sub))
		{
			free(sub);
			return (ft_strdup("0"));
		}
		else
			s = sub;
	}
	return (trim_zero(s));
}

int	print_base16(va_list args, char c, int *l_conversion)
{
	char		*s;
	long long	hex;
	char		*conv;

	hex = (long long)va_arg(args, long long);
	if (c == 'X')
		s = trim_char(convert_int2_hex(hex, 1));
	else
	{
		if (c == 'p')
		{
			conv = convert_int2_hex(hex, 0);
			s = ft_strjoin("0x", conv);
			free(conv);
		}
		if (c == 'x')
		{
			s = trim_char(convert_int2_hex(hex, 0));
		}
	}
	ft_putstr_fd(s, 1);
	*l_conversion += ft_strlen(s);
	free(s);
	return (1);
}
