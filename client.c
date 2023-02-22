/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:05:56 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/22 14:25:25 by sgomez-p         ###   ########.fr       */
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
        write(1, "\n", 1);
        exit (0);
    }
}

static void mt_kill(int pid, char *str)
{
    int i;
    char c;

    while (*str)
    {
        i = 8;
        c = *str++;

        while (i--)
        {
            if (c >> i & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);

            usleep(200);
        }
    }
    i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1);
        usleep(200);
    }
}

int	main(int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return (1);
    write(1, "Enviado: ", 9);
    ft_putnbr_fd(ft_strlen(argv[2]), 1);
    write(1, "\n", 1);
    write(1, "Recibido: ", 10);
    signal(SIGUSR1, action);
    signal(SIGUSR2, action);
    mt_kill(ft_atoi(argv[1]), argv[2]);
    while(1)
        pause();
    return (0);
}
