/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:45:26 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/11 17:40:52 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (count == 18446744073709551615UL || size == 18446744073709551615UL)
		return (NULL);
	temp = (void *) malloc(size * count);
	if (!temp)
		return (NULL);
	ft_bzero(temp, size * count);
	return (temp);
}
