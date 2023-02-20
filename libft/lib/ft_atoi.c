/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:32:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/20 15:53:09 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				cont_minus;
	unsigned int	res;

	cont_minus = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			cont_minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	if (res > 2147483648 && cont_minus == -1)
		return (0);
	if (res > 2147483647 && cont_minus == 1)
		return (-1);
	return (res * cont_minus);
}

/*int		main(void)
{
	printf("%d\n", ft_atoi("      	---+--46541zzza56"));

}*/
