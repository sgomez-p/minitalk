/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:13:53 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/03 16:08:04 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf_str ("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_printf_char(str[i]);
		i++;
	}
	return (i);
}
