/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:31:30 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/08 15:17:10 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	server_start(void)
{
	char	*str_pid;

	str_pid = ft_itoa(getpid());
	ft_putstr("Start client with this sintaxe: ./client [PID] [string]\n");
	write(1, "PID = ", 6);
	ft_putstr(str_pid);
	write(1, "\n", 1);
}

void	handler(int sig)
{
	static int	i = 0;
	static char	c = 0;
	int			bit;

	if (sig == SIGUSR1)
		bit = 1;
	if (sig == SIGUSR2)
		bit = 0;
	c += (bit << i++);
	if (i >= 7)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Server don't have paramenters\nUse only: ./server\n");
		return (1);
	}
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
	return (0);
}
