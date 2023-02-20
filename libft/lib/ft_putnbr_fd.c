/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:03:15 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/09/29 14:28:49 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = (number * -1);
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	number = number % 10;
	if (number < 10)
		ft_putchar_fd(number + 48, fd);
}
