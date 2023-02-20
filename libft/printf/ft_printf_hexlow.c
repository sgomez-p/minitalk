/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:04:49 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 15:51:16 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexlow(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base(n, "0123456789abcdef");
	i = ft_printf_str(str);
	free (str);
	return (i);
}
