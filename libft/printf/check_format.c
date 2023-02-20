/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:11:39 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 15:57:05 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list ap, const char format)
{	
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printf_char(va_arg(ap, int));
	else if (format == 's')
		len = ft_printf_str(va_arg(ap, char *));
	else if (format == 'p')
		len = ft_printf_void_hex(va_arg(ap, void *));
	else if (format == 'i' || format == 'd')
		len = ft_printf_int(va_arg(ap, int));
	else if (format == 'u')
		len = ft_printf_unsigned_int(va_arg(ap, unsigned int));
	else if (format == 'x')
		len = ft_printf_hexlow(va_arg(ap, unsigned long));
	else if (format == 'X')
		len = ft_printf_hexup(va_arg(ap, unsigned long));
	else if (format == '%')
		len = ft_printf_per();
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start (ap, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_format(ap, str[i + 1]);
			i++;
		}
		else
			len += ft_printf_char(str[i]);
		i++;
	}
	va_end (ap);
	return (len);
}
