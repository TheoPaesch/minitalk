/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:34 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/20 13:01:23 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	num_send(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit < 16)
	{
		kill(pid, SIGUSR1 + !(len & (0x01 << bit++)));
		usleep(50);
	}
}

static void	bit_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		kill(pid, SIGUSR1 + !(c & (0x01 << bit++)));
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 3)
		ft_error(0);
	else if (argc > 3)
		ft_error(1);
	else
	{
		num_send(ft_atoi(argv[1]), ft_strlen(argv[2]));
		while (argv[2][i] != '\0')
			bit_send(ft_atoi(argv[1]), argv[2][i++]);
		bit_send(ft_atoi(argv[1]), argv[2][i]);
	}
	return (0);
}
