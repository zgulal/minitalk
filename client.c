/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:19:45 by zgulal            #+#    #+#             */
/*   Updated: 2023/03/24 17:31:49 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sigctrl;

void	kill_func(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c >> i) & 1)
			g_sigctrl = kill(pid, SIGUSR1);
		else
			g_sigctrl = kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	g_sigctrl = -1;
	if (ac == 3)
		while (av[2][i])
			kill_func(ft_atoi(av[1]), av[2][i++]);
	else
	{
		ft_printf("You've entered too many or too few argument !\n");
		return (1);
	}
	if (g_sigctrl == 0)
		ft_printf("You've been sent the signal succesfully !\n");
	else
		ft_printf("You couldn't send the signal successfully !\n");
	return (0);
}
