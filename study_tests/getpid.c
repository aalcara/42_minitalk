/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:01:27 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/05 09:12:55 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;
	pid_t	pid2;

	pid = getpid();
	printf("\npid = %d\n", pid);
	pid2 = getpid();
	printf("\nsame pid = %d\n", pid2);
}