/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:31:30 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/09 10:41:47 by aalcara-         ###   ########.fr       */
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
	static int	j = 0;
	static char	str[100];
	int			bit;

	if (i >= 7)
	{
		j++;
		i = 0;
	}
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	str[j] += (bit << i++);
	if (i >= 7 && (str[j] == '\0' || j == 49))
	{
		ft_putstr(str);
		if (str[j] == '\0')
			ft_putchar('\n');
		ft_memset(str, '\0', 100);
		i = 0;
		j = 0;
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
