/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:31:30 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/06 20:34:31 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	server_start(void)
{
	char	*str_pid;

	str_pid = ft_itoa(getpid());
	write(1, "Start client with this sintaxe: ./client [pid] [string]\n", 56);
	write(1, "pid = ", 6);
	ft_putstr(str_pid);
	write(1, "\n", 1);
}

void	handler(int sig)
{
	// usleep(1);
	if (sig == SIGUSR1)
		ft_putchar('1');
	if (sig == SIGUSR2)
		ft_putchar('0');
}

int	main(void)
{
	server_start();
	if (signal(SIGUSR1, handler) == SIG_ERR)
	{
		ft_putstr("Error on signal receiver");
		return (0);
	}
	if (signal(SIGUSR2, handler) == SIG_ERR)
	{
		ft_putstr("Error on signal receiver");
		return (0);
	}
	while (1)
		pause();
}
