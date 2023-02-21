/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:05:56 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/21 12:44:50 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/lib/libft.h"

static void	action(int sig)
{
	static int	recieved = 0;

	if (sig == SIGUSR1)
		++recieved;
	else
	{
		ft_putnbr_fd(recieved, 1);
		ft_putchar_fd('\n', 1);
		exit (0);
	}
}

static void mt_kill(int pid, char *str)
{
    int i; // índice para recorrer cada bit de la cadena
    char c; // variable que almacena el caracter actual de la cadena

    while (*str)
    {
        i = 8;
        c = *str++; // obtiene el siguiente caracter de la cadena y avanza al siguiente

        while (i--) // mientras no se han enviado todos los bits de un caracter
        {
            // si el bit actual es un 1, envía la señal SIGUSR2 al proceso con PID "pid"
            if (c >> i & 1)
                kill(pid, SIGUSR2);
            // si el bit actual es un 0, envía la señal SIGUSR1 al proceso con PID "pid"
            else
                kill(pid, SIGUSR1);

            usleep(100); // espera 100 microsegundos antes de enviar el siguiente bit
        }
    }
    // Se envían 8 señales SIGUSR1 adicionales para indicar el final del mensaje. pq?
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);
        usleep(100);
    }
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2])) // comprobamos que solo 2 argumentos y que el segundo no esta vacio
		return (1);
	ft_putstr_fd("Enviado: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Recibido: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]); // pilla el PID y segun si es 1 o 0 SIGUR1 o 2
	while(1)
		pause(); // se suspende la ejecucion del programa hasta q recibe otra señal
	return (0);
}
