/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:05:32 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/13 15:12:06 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = 0;
		return (substr);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (len-- > 0)
	{
		substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}
