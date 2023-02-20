/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:26:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/10 12:57:02 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	p;
	size_t	c;

	p = 0;
	c = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (p < len && s1[p] != 0)
	{
		while (s1[p + c] == s2[c] && s1[p + c] && (p + c) < len)
		{
			if (s1[p + c] == 0 && s2[c] == 0)
				return ((char *)&s1[p]);
			c++;
		}
		if (s2[c] == 0)
			return ((char *)s1 + p);
		p++;
		c = 0;
	}
	return (0);
}
