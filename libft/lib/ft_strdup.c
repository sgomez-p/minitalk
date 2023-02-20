/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/09/26 13:17:17 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*p;

	i = 0;
	n = ft_strlen(s1);
	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	while (i <= n)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
