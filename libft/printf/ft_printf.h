/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:23:27 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/10/24 09:29:43 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

int		check_format(va_list ap, const char format);
char	*ft_itoa_base(unsigned long long n, char *base);
int		ft_printf_str(char *str);
int		ft_printf_char(char s);
int		ft_printf_unsigned_int(unsigned int n);
int		ft_printf_void_hex(void *address);
int		ft_printf_hexup(unsigned int n);
int		ft_printf_hexlow(unsigned int n);
int		ft_printf_int(int n);
int		ft_printf(char const *str, ...);
size_t	ft_strlen(char *str);
void	ft_bzero(void *s, unsigned int n);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, unsigned int n);
int		ft_printf_per(void);
#endif