/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:01:27 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/06 10:48:24 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// int	main(void)
// {
// 	int	num = 10;
	
// 	while (num > 0)
// 	{
// 		printf ("\nn = %d\t", num);
// 		if ((num & 1) == 1)
// 			printf("1");
// 		else
// 			printf("0");
// 		num--;
// 	}
// }

int	main(void)
{
	int	num = 60;
	int	ref	= 128;
	
	printf("\nnum = %d\n", num);
	while (ref >= 1)
	{
		if (ref == 8)
			printf(" ");
		if (num >= ref)
		{
			printf("1");
			num = num - ref;
		}
		else
			printf("0");
		ref = ref / 2;
	}
	printf("\n");
}