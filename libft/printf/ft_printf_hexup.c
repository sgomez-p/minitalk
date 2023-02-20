/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:24:22 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/20 15:50:53 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexup(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base(n, "0123456789ABCDEF");
	i = ft_printf_str(str);
	free (str);
	return (i);
}
