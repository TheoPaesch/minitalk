/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:34:40 by tpaesch           #+#    #+#             */
/*   Updated: 2024/02/19 22:57:54 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/ft_printf.h"
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_assist
{
	char	*str;
	char	c;
	int		flag;
	int		bit;
	int		j;
}	t_assist;

void	ft_error(int i);

#endif