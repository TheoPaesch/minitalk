/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:23:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/17 18:45:01 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	def_char(int signal)
{
	static int	i;
	static int	bit;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 0)
	{
		ft_error(0);
		return (0);
	}
	else if (argc > 1)
	{
		ft_error(1);
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argv[0])
	{
		signal(SIGUSR1, def_char);
		signal(SIGUSR2, def_char);
		pause();
	}
	return (0);
}
