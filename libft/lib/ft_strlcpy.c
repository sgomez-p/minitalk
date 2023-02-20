/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:12:28 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/10 14:40:06 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	dest[];
	char	src[];
	int		a;

	dest[] = "1234";
	src[] = "ofensiva";
	ft_strlcpy(dest, src, 9);
	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		printf("%c", dest[a]);
		a++;
	}
}
*/