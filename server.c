/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:19:34 by zgulal            #+#    #+#             */
/*   Updated: 2023/03/24 16:41:46 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	read_bits(int signal)
{
	static int	n;
	static int	result;

	if (signal == SIGUSR1)
		(result += (1 << n));
	n++;
	if (n == 8)
	{
		write(1, &result, 1);
		result = 0;
		n = 0;
	}
}

int	main(void)
{
	ft_printf("Your process number is : %d\n", getpid());
	signal(SIGUSR1, read_bits);
	signal(SIGUSR2, read_bits);
	while (1)
		continue ;
}
