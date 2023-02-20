/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:36:34 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 15:48:10 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_negative(int *n)
{
	int	i;

	i = 0;
	if (*n == INT_MIN)
	{
		i = 1;
		ft_printf_char('-');
		ft_printf_char('2');
		*n = 147483648;
		i++;
	}
	else if (*n < 0)
	{
		ft_printf_char('-');
		*n *= -1;
		i++;
	}
	return (i);
}

int	ft_printf_int(int n)
{
	int		i;
	char	*str;

	i = ft_int_negative(&n);
	str = ft_itoa_base(n, "0123456789");
	i = i + ft_printf_str(str);
	free (str);
	return (i);
}
