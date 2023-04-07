/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:30:50 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/06 17:50:10 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "./libft/libft.h"

/**
 * @brief Iterates each character of str
 * from LSB to MSB, sending bit by bit to the Server's PID;
 * send USR1 when a bit is 1, and USR2 otherwise. 
 * @param str 
 * @param pid 
 * @return int 
 */
int	ft_send_fax(char *str, int pid)
{
	int		i;
	char	c;

	while (*str)
	{		
		c = *str;
		i = 0;
		while (i < 8)
		{
			if (c & 1 << i)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	ft_send_fax(argv[2], pid);
	return (0);
}
