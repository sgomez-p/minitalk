/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:01:43 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/09/26 16:26:39 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*memory;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	memory = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!memory)
		return (NULL);
	while (s1[i])
	{
			memory[j++] = s1[i];
			i++;
	}
	i = 0;
	while (s2[i])
	{
			memory[j++] = s2[i];
			i++;
	}
	memory[j] = 0;
	return (memory);
}
