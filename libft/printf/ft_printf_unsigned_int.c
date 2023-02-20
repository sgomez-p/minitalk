/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:37:15 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 14:10:56 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_int(unsigned int n)
{
	int		i;
	char	*str;

	str = ft_itoa_base(n, "0123456789");
	i = ft_printf_str(str);
	free (str);
	return (i);
}
