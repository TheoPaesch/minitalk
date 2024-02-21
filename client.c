/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:34 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/21 14:20:01 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static void	cdef_char(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		if (signal == SIGUSR1)
			i |= (0x01 << bit);
		bit++;
		if (bit == 16)
		{
			ft_printf("-------------------\n");
			ft_printf("accepted message : %d\n", i);
			ft_printf("-------------------\n");
			bit = 0;
			i = 0;
			exit(EXIT_SUCCESS);
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	cpid;

	signal(SIGUSR1, cdef_char);
	signal(SIGUSR2, cdef_char);

	i = 0;
	if (argc < 3)
		ft_error(0);
	else if (argc > 3)
		ft_error(1);
	else
	{
		cpid = getpid();
		num_send(ft_atoi(argv[1]), ft_strlen(argv[2]));
		num_send(ft_atoi(argv[1]), cpid);
		while (argv[2][i] != '\0')
			bit_send(ft_atoi(argv[1]), argv[2][i++]);
		bit_send(ft_atoi(argv[1]), argv[2][i]);
	}
	while (1)
		pause();
	return (0);
}
