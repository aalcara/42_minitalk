/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:38:04 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/06 20:35:30 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	separator(char c, pid_t pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i <= 7)
	{
		usleep(1000);
		if (((c >> i) & 1) == 1)
		{
			error = kill(pid, SIGUSR1);
			ft_putchar('1');

		}
		else
		{
			error = kill(pid, SIGUSR2);
			ft_putchar('0');
		}
		if (error != 0)
		{
			write(1, "Error on kill function!\n", 24);
			exit(0);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Incorrect Args!", 15);
		return (0);
	}
	while (argv[i][2] != '\0')
	{
		ft_putchar(argv[2][i]);
		separator(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	
}