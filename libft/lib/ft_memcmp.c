/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:47:52 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/10 14:39:20 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	while (n--)
	{
		uc1 = *(unsigned char *)s1;
		uc2 = *(unsigned char *)s2;
		while (uc1 != uc2)
		{
			return (uc1 - uc2);
		}
		s1++;
		s2++;
	}
	return (0);
}
