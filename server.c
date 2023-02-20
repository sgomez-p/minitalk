/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:05:48 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:37 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/lib/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0; // contador para saber cuándo se han recibido 8 bits
	static pid_t			client_pid = 0; // PID del cliente que envía la señal
	static unsigned char	c = 0; // carácter que se va a recibir, bit por bit

	(void)context; // evita una advertencia por no utilizar el parámetro
	if (!client_pid)
		client_pid = info->si_pid; // si es la primera señal que recibe, obtiene el PID del cliente
	c |= (sig == SIGUSR2); // se asigna el bit que se ha recibido en el carácter
	if (++i == 8)
	{
		i = 0;
		if (!c) // si el carácter es 0, es el fin del mensaje
		{
			kill(client_pid, SIGUSR2); // envía una señal SIGUSR2 al cliente para indicar que se ha recibido el mensaje completo
			client_pid = 0; // reinicia el PID del cliente
			return ;
		}
		ft_putchar_fd(c, 1); // muestra el carácter recibido
		c = 0; // reinicia el carácter
		kill(client_pid, SIGUSR1); // envía una señal SIGUSR1 al cliente para indicar que está listo para recibir el siguiente carácter
	}
	else
		c <<= 1; // desplaza el carácter hacia la izquierda para hacer espacio al siguiente bit
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1); // muestra el PID del servidor
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action; // indica la función que se va a llamar cuando se reciba una señal
	s_sigaction.sa_flags = SA_SIGINFO; // indica que se quiere obtener información adicional sobre la señal
	sigaction(SIGUSR1, &s_sigaction, 0); // establece la función de acción para la señal SIGUSR1
	sigaction(SIGUSR2, &s_sigaction, 0); // establece la función de acción para la señal SIGUSR2
	while (1)
		pause(); // espera a que se reciba una señal
	return (0);
}
