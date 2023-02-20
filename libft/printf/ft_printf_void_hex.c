/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:00:30 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 15:42:18 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prefix_point(char *str)
{
	int	i;

	i = ft_printf_str(str);
	return (i);
}

int	ft_printf_void_hex(void *address)
{
	unsigned long	l;
	int				i;
	char			*str;

	l = (unsigned long)address;
	i = ft_prefix_point("0x");
	str = ft_itoa_base(l, "0123456789abcdef");
	i += ft_printf_str(str);
	free (str);
	return (i);
}
