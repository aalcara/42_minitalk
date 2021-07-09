/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:38:04 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/09 10:19:12 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	send_char(char c, pid_t pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i <= 7)
	{
		usleep(2000);
		if (((c >> i) & 1) == 1)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		if (error != 0)
		{
			ft_putstr("Wrong PID!\n");
			exit (1);
		}
		i++;
	}
	return (0);
}	

int	send_message(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (send_char(str[i], pid))
			return (1);
		i++;
	}
	if (str[i] == '\0')
	{
		if (send_char(str[i], pid))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	send_pid(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i] > 0 && str[i] <= 126)
	{
		if (send_char(str[i], pid))
			return (1);
		i++;
	}
	if (str[i] == '\0')
	{
		if (send_char(str[i], pid))
			return (1);
	}
	else
		return (1);
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("String delivered at server!!!\n");
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*client_pid;

	if (argc != 3)
	{
		write(1, "Incorrect Args!\n", 16);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	client_pid = ft_itoa(getpid());
	send_pid(client_pid, pid);
	if (send_message(argv[2], pid))
	{
		ft_putstr("Something went Wrong!\n");
		return (0);
	}
	signal(SIGUSR1, handler);
	pause();
	return (0);
}
