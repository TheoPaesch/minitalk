/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:23:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/19 23:41:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_struct(t_assist *assist)
{
	assist->str = NULL;
	assist->flag = 1;
	assist->bit = 0;
	assist->c = 0;
	assist->j = 0;
}

static void	i_need_space(t_assist *assist, int f)
{
	if (f == 1)
	{
		assist->str[assist->j] = assist->c;
		assist->j++;
	}
	else if (f == 0)
	{
		assist->str[assist->j] = assist->c;
		ft_printf("%s", assist->str);
		free(assist->str);
		set_struct(assist);
	}
}

static int	get_len(int signal, char **str, int *flag)
{
	static int	i = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 16)
	{
		*str = malloc((i + 1) * sizeof(char));
		if (str == NULL)
			exit(EXIT_FAILURE);
		*flag = 0;
		bit = 0;
		i = 0;
	}
	return (0);
}

static void	def_char(int signal)
{
	static t_assist	assist;
	static int		init = 1;

	if (init)
	{
		set_struct(&assist);
		init = 0;
	}
	if (assist.flag == 1)
		get_len(signal, &assist.str, &assist.flag);
	else if (assist.flag == 0)
	{
		if (signal == SIGUSR1)
			assist.c |= (0x01 << assist.bit);
		assist.bit++;
		if (assist.bit == 8)
		{
			i_need_space(&assist, 1);
			if (assist.c == '\0')
				i_need_space(&assist, 0);
			assist.bit = 0;
			assist.c = 0;
		}
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
