/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:31:30 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/09 17:53:30 by aalcara-         ###   ########.fr       */
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

int	ft_getclientpid(int *i, char *str)
{
	int	client_pid;

	i[2]++;
	client_pid = ft_atoi(str);
	i[1] = 0;
	i[0] = 0;
	return (ft_atoi(str));
}

void	putbuff(char *str, int *i, int client_pid)
{
	ft_putstr(str);
	if (str[i[1]] == '\0')
	{
		i[2]++;
		ft_putchar('\n');
		kill(client_pid, SIGUSR1);
	}
	i[0] = 0;
	i[1] = 0;
}
void	handler(int sig)
{
	static int	i[3] = {0, 0, 2};
	static char	str[100];
	int			bit;
	static int	client_pid = 0;

	if (i[0] > 7)
	{
		i[1]++;
		i[0] = 0;
	}
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	str[i[1]] += (bit << i[0]++);
	if (i[0] > 7 && str[i[1]] == '\0' && (i[2] % 2 == 0))
	{
		client_pid = ft_getclientpid(&i[0], str);
		ft_memset(str, '\0', 100);
	}
	if (i[0] > 7 && (str[i[1]] == '\0' || i[1] == 50))
	{
		putbuff(str, &i[0], client_pid);
		ft_memset(str, '\0', 100);
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
