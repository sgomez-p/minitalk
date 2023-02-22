/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:05:48 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/22 14:17:35 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/lib/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void action(int sig, siginfo_t *info, void *context)
{
    static int i = 0;
    static pid_t client_pid = 0;
    static unsigned char c = 0;
    static unsigned char mask = 0b10000000;

    (void)context;
    if (!client_pid)
        client_pid = info->si_pid;
    if (sig == SIGUSR2)
        c |= mask;
    mask >>= 1;
    if (++i == 8)
    {
        i = 0;
        if (!c)
        {
            kill(client_pid, SIGUSR2);
            client_pid = 0;
            mask = 0b10000000;
            return ;
        }
        write(1, &c, 1);
        c = 0;
        mask = 0b10000000;
        kill(client_pid, SIGUSR1);
    }
}

int main(void)
{
    struct sigaction s_sigaction;

    write(1, "PID del server: ", 16);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    s_sigaction.sa_sigaction = action;
    s_sigaction.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s_sigaction, 0);
    sigaction(SIGUSR2, &s_sigaction, 0);
    while (1)
        pause();
    return (0);
}
